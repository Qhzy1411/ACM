#include <algorithm>
#include <cctype>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <direct.h>
#include <windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

using namespace std;
#define endl '\n'

// --- 测试配置 ---
// 切换测试模式
// 设置为 false: 使用 generator.exe 和 std.exe 生成数据和标准输出 (原始行为)
// 设置为 true:  使用 "testcase" 文件夹下现有的 .in 和 .out 文件进行测试
const bool USE_EXISTING_TESTCASES = 0;

const int NUM_TESTS = 100;          // [随机生成模式] 测试点数量
const int EXISTING_TEST_COUNT = 20; // [使用现有数据模式] .in/.out文件的数量
const int TIME_LIMIT_MS = 1000;     // 测试程序运行时限 (ms)

// 给本地运行分配的最大栈空间 (MB)
const int STACK_MB_SIZE = 256;

const string GENERATOR = "generator"; // 数据生成器文件名
const string TEST = "test";           // 需要测试程序文件名
const string STD = "std";             // 正解程序文件名

const string DATA_DIR = "data";         // 存放输出日志的文件夹
const string TESTCASE_DIR = "testcase"; // 存放现有测试数据的文件夹

// --- 编译和程序配置 ---
// 注意：请确保你的 C++ 编译器 (如 g++) 已经加入了系统环境变量 PATH 中

const long long STACK_SIZE = STACK_MB_SIZE * 1024 * 1024;
const string CPP_COMPILER = "g++";
const string CPP_FLAGS = "-O3 -std=c++17 -static-libgcc -finput-charset=UTF-8 -fexec-charset=UTF-8 -Wl,--stack," + to_string(STACK_SIZE); // -O3优化, C++17标准, 静态链接(推荐Windows下使用), 扩大栈空间

// --- 文件路径配置 ---
const string GENERATOR_SRC = GENERATOR + ".cpp";
const string TEST_SRC = TEST + ".cpp";
const string STD_SRC = STD + ".cpp";
const string GENERATOR_EXE = GENERATOR + ".exe";
const string TEST_EXE = TEST + ".exe";
const string STD_EXE = STD + ".exe";

#ifdef _WIN32
const char PATH_SEP = '\\';
const string MKDIR_CMD = "mkdir " + DATA_DIR;
const string RMDIR_CMD = "rd /s /q ";
#else
const char PATH_SEP = '/';
const string MKDIR_CMD = "mkdir -p " + DATA_DIR;
const string RMDIR_CMD = "rm -rf ";
#endif

const string IN_FILE = DATA_DIR + PATH_SEP + "test.in";
const string TEST_OUT_FILE = DATA_DIR + PATH_SEP + "test.out";
const string STD_OUT_FILE = DATA_DIR + PATH_SEP + "std.out";

// 检查目录是否存在
bool directory_exists(const string &dir_path) {
#ifdef _WIN32
    DWORD ftyp = GetFileAttributesA(dir_path.c_str());
    if (ftyp == INVALID_FILE_ATTRIBUTES) {
        return false;
    }
    return (ftyp & FILE_ATTRIBUTE_DIRECTORY);
#else
    struct stat info;
    if (stat(dir_path.c_str(), &info) != 0) {
        return false;
    }
    return (info.st_mode & S_ISDIR);
#endif
}

// 清空并重建目录
void clear_directory(const string &dir_path) {
    // 使用系统命令简单高效地删除目录及其内容
    string command = RMDIR_CMD + dir_path;
    system(command.c_str());
    system(MKDIR_CMD.c_str());
    cout << "目录 '" << dir_path << "' 已清空并重建。" << endl
         << endl;
}

// 编译一个 C++ 源文件
bool compile_program(const string &source_file, const string &output_exe) {
    string compile_cmd = CPP_COMPILER + " " + CPP_FLAGS + " " + source_file + " -o " + output_exe;
    cout << "正在编译: " << compile_cmd << endl;
    if (system(compile_cmd.c_str()) != 0) {
        cerr << "编译失败: " << source_file << endl;
        return false;
    }
    return true;
}

// 比较两个文件内容是否相同 (忽略行末空格和换行符差异)
bool compare_files(const string &file1, const string &file2) {
    ifstream f1(file1);
    ifstream f2(file2);
    if (f1.fail() || f2.fail()) {
        cerr << "无法打开比较文件！" << endl;
        return false; // 文件打开失败
    }
    string line1, line2;
    while (true) {
        // 从两个文件中分别读取一行
        bool has_line1 = static_cast<bool>(getline(f1, line1));
        bool has_line2 = static_cast<bool>(getline(f2, line2));
        // 如果一个文件有下一行而另一个没有，说明行数不同
        if (has_line1 != has_line2) {
            return false;
        }
        // 如果两个文件都已读到末尾，说明它们完全相同
        if (!has_line1) {
            return true;
        }
        // --- 核心逻辑：修剪行末空白 ---
        // 辅助函数：移除字符串末尾的空格和制表符
        auto trim_trailing_whitespace = [](string &s) {
            const string whitespace = " \t";
            const auto last_char = s.find_last_not_of(whitespace);
            if (string::npos != last_char) {
                s.erase(last_char + 1);
            } else {
                s.clear();
            }
        };
        trim_trailing_whitespace(line1);
        trim_trailing_whitespace(line2);
        // 比较修剪后的两行
        if (line1 != line2) {
            return false;
        }
    }
}

// 生成详细的差异日志文件
void generate_diff_log(const string &std_file, const string &test_file, const string &log_file) {
#ifdef _WIN32
    // 在Windows上, 使用 `fc /N` 可以显示行号，非常有助于调试
    string cmd = "fc /N " + std_file + " " + test_file + " > " + log_file;
#else
    // 在Linux/macOS上, 使用 `diff -u` (unified format) 是标准做法，上下文清晰
    string cmd = "diff -u " + std_file + " " + test_file + " > " + log_file;
#endif
    system(cmd.c_str());
}

int main() {
    // 禁用 C++ 流与 C 标准流的同步，加速 cin/cout
    // ios_base::sync_with_testio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    // 检查并询问是否清空 data 文件夹
    if (directory_exists(DATA_DIR)) {
        cout << "检测到已存在 'data' 文件夹。是否清空其中的内容? (y/n): ";
        char response;
        cin >> response;
        // 清除cin缓冲区中的换行符
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (tolower(response) == 'y') {
            clear_directory(DATA_DIR);
        } else {
            cout << "将保留 'data' 文件夹的现有内容。" << endl;
        }
    } else {
        system(MKDIR_CMD.c_str());
    }
    cout << endl;

    if (USE_EXISTING_TESTCASES) {
        cout << "--- 使用现有测试数据 ---" << endl
             << endl;
    } else {
        cout << "--- 使用随机生成数据 ---" << endl
             << endl;
    }
    cout << "--- 开始编译程序 ---" << endl;
    bool compile_ok = compile_program(TEST_SRC, TEST_EXE);
    if (!USE_EXISTING_TESTCASES) {
        // 如果是生成模式，才需要编译生成器和暴力程序
        compile_ok = compile_program(GENERATOR_SRC, GENERATOR_EXE) && compile_ok;
        compile_ok = compile_program(STD_SRC, STD_EXE) && compile_ok;
    }

    if (!compile_ok) {
        cerr << "一个或多个程序编译失败，对拍终止。" << endl;
        return 1;
    }
    cout << "--- 所有程序编译成功 ---" << endl
         << endl;

    int ac_count = 0;
    int wa_count = 0;
    int tle_count = 0;
    int re_count = 0;
    long long max_duration_ms = 0;

    int total_tests = USE_EXISTING_TESTCASES ? EXISTING_TEST_COUNT : NUM_TESTS;

    for (int i = 1; i <= total_tests; i++) {
        string current_in_file = IN_FILE;
        string current_std_out_file = STD_OUT_FILE;
        string current_test_out_file = TEST_OUT_FILE;

        if (USE_EXISTING_TESTCASES) {
            current_in_file = TESTCASE_DIR + PATH_SEP + to_string(i) + ".in";
            current_std_out_file = TESTCASE_DIR + PATH_SEP + to_string(i) + ".out";

            // 检查输入文件是否存在
            ifstream infile_check(current_in_file);
            if (!infile_check) {
                cerr << "错误: 找不到输入文件 " << current_in_file << "，测试中断。" << endl;
                break;
            }
            // 检查输出文件是否存在
            ifstream outfile_check(current_std_out_file);
            if (!outfile_check) {
                cerr << "错误: 找不到标准答案文件 " << current_std_out_file << "，测试中断。" << endl;
                break;
            }
        } else {
            // 随机生成模式
            system((GENERATOR_EXE + " > " + current_in_file).c_str());
            system((STD_EXE + " < " + current_in_file + " > " + current_std_out_file).c_str());
        }

        auto start_time = chrono::high_resolution_clock::now();
        int test_status = system((TEST_EXE + " < " + current_in_file + " > " + current_test_out_file).c_str());
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

        if (test_status == 0) {
            max_duration_ms = max(max_duration_ms, duration.count());
        }

        if (test_status != 0) {
            re_count++;
            cout << "测试点#" << i << " Runtime Error" << endl;
            // RE，保存输入文件
            string re_in = DATA_DIR + PATH_SEP + "re_" + to_string(i) + ".in";
            if (USE_EXISTING_TESTCASES) {
                ifstream src_in(current_in_file, ios::binary);
                ofstream dst_in(re_in, ios::binary);
                dst_in << src_in.rdbuf();
            } else {
                rename(current_in_file.c_str(), re_in.c_str());
            }
            continue;
        }

        bool passed = true;
        if (duration.count() > TIME_LIMIT_MS) {
            tle_count++;
            cout << "测试点#" << i << " Time Limited Exceeded，用时 " << duration.count() << " ms" << endl;
            // TLE，保存输入文件
            string tle_in = DATA_DIR + PATH_SEP + "tle_" + to_string(i) + ".in";
            if (USE_EXISTING_TESTCASES) {
                ifstream src_in(current_in_file, ios::binary);
                ofstream dst_in(tle_in, ios::binary);
                dst_in << src_in.rdbuf();
            } else {
                rename(current_in_file.c_str(), tle_in.c_str());
            }
            passed = false;
        }

        if (!compare_files(current_std_out_file, current_test_out_file)) {
            if (passed)
                wa_count++;
            cout << "测试点#" << i << " Wrong Answer，用时 " << duration.count() << " ms" << endl;
            // 生成wa.log差异文件
            string wa_log_file = DATA_DIR + PATH_SEP + "wa_" + to_string(i) + ".log";
            generate_diff_log(current_std_out_file, current_test_out_file, wa_log_file);

            // WA，保存所有相关文件
            string wa_in = DATA_DIR + PATH_SEP + "wa_" + to_string(i) + ".in";
            string wa_std_out = DATA_DIR + PATH_SEP + "wa_" + to_string(i) + ".std.out";
            string wa_test_out = DATA_DIR + PATH_SEP + "wa_" + to_string(i) + ".test.out";

            // 如果使用现有数据，就复制而不是重命名
            if (USE_EXISTING_TESTCASES) {
                ifstream src_in(current_in_file, ios::binary);
                ofstream dst_in(wa_in, ios::binary);
                dst_in << src_in.rdbuf();

                ifstream src_std_out(current_std_out_file, ios::binary);
                ofstream dst_std_out(wa_std_out, ios::binary);
                dst_std_out << src_std_out.rdbuf();
            } else {
                rename(current_in_file.c_str(), wa_in.c_str());
                rename(current_std_out_file.c_str(), wa_std_out.c_str());
            }
            rename(current_test_out_file.c_str(), wa_test_out.c_str());
            passed = false;
        }

        if (passed) {
            ac_count++;
            cout << "测试点#" << i << " Accepted，用时 " << duration.count() << " ms" << endl;
        }
    }

    // 输出总结并清理
    cout << endl;
    cout << "--- 对拍结果统计 ---" << endl;
    cout << "Accepted (AC):             " << ac_count << endl;
    cout << "Wrong Answer (WA):         " << wa_count << endl;
    cout << "Time Limit Exceeded (TLE): " << tle_count << endl;
    cout << "Runtime Error (RE):        " << re_count << endl;
    cout << "最大运行时长:              " << max_duration_ms << " ms" << endl;

    double score = total_tests > 0 ? 100.0 * ac_count / total_tests : 0.0;
    cout << "\n共 " << total_tests << " 组测试数据，得分"
         << fixed << setprecision(2) << score << "。" << endl;

    // 清理临时文件和编译出的程序
    if (!USE_EXISTING_TESTCASES) {
        remove(IN_FILE.c_str());
        remove(STD_OUT_FILE.c_str());
        remove(GENERATOR_EXE.c_str());
        remove(STD_EXE.c_str());
    }
    remove(TEST_OUT_FILE.c_str());
    remove(TEST_EXE.c_str());

    return 0;
}