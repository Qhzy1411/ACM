#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

// --- 为了代码的简洁性和可读性，这里只保留了必要的 using 声明和模板 ---
using namespace std;
using ll = long long;
using pii = pair<int, int>;

// 使用 chrono 来获取更随机的种子
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// --- 常用数据生成函数 ---

/**
 * @brief 生成 [L, R] 范围内的随机整数
 * @param L 范围下界
 * @param R 范围上界
 * @return long long 随机生成的整数
 */
ll rand_int(ll L, ll R) {
    uniform_int_distribution<ll> dist(L, R);
    return dist(rng);
}

/**
 * @brief 生成一个长度为 n 的随机二进制字符串
 * @param n 字符串的长度
 * @return string 随机生成的二进制字符串
 */
string rand_binary_string(int n) {
    string s;
    s.reserve(n); // 预分配内存以提高效率
    for (int i = 0; i < n; ++i) {
        s += to_string(rand_int(0, 1));
    }
    return s;
}

int main() {
    // 禁用 C++ 标准流与 C 标准流的同步，并解除 cin 和 cout 的绑定，以加速 IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // --- 数据生成逻辑 ---

    // 题目约束：所有测试用例的 n 的总和不超过 10^6
    const int SUM_N_LIMIT = 1000000;
    int remaining_n = SUM_N_LIMIT;

    vector<pair<int, string>> test_cases;

    // 循环生成测试用例，直到 n 的总和达到上限
    // 确保 remaining_n 至少为 3，因为题目要求 n >= 3
    while (remaining_n >= 3) {
        // 为了生成更多样的测试用例，可以为单个 n 设置一个上限
        // 例如，最大 n 不超过 200000，这样可以避免单个用例过大，从而生成更多的用例
        int max_n_for_this_case = min(remaining_n, 200000);
        int n = rand_int(3, max_n_for_this_case);

        remaining_n -= n;

        // 生成长度为 n 的随机二进制字符串
        string s = rand_binary_string(n);
        test_cases.push_back({n, s});
    }

    // 首先输出测试用例的总数 T
    cout << test_cases.size() << endl;

    // 然后逐个输出每个测试用例
    for (const auto &tc : test_cases) {
        cout << tc.first << endl;  // 输出 n
        cout << tc.second << endl; // 输出二进制字符串 s
    }

    return 0;
}