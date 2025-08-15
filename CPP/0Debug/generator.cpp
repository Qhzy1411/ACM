#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

// --- 您提供的文件头 ---
using namespace std;
using ll = long long;
using pii = pair<int, int>;

// 使用 chrono 来获取更随机的种子
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
// --- 文件头结束 ---

/**
 * @brief 为单个测试用例生成数据并打印
 */
void generate_case() {
    // 题目约束：1 <= n <= 400, 1 <= m <= 2, 0 <= a_i <= 100
    int n = rand_int(1, 5);
    int m = rand_int(1, 2);

    // 打印 n 和 m
    cout << n << " " << m << "\n";

    // 打印 n 个 affection 值
    for (int i = 0; i < n; ++i) {
        cout << rand_int(0, 30) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main(int argc, char *argv[]) {
    // 提高 I/O 效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 确定测试用例数量 T
    int T = rand_int(1, 10);

    // 打印测试用例总数 T
    cout << T << "\n";

    // 循环生成 T 个测试用例
    while (T--) {
        generate_case();
    }

    return 0;
}