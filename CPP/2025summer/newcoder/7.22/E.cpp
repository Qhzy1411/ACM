#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll
vector<int> primes;
bool is_prime[5000005];
void linearSieve(int n) {
    is_prime[0] = is_prime[1] = true;
    for (int i = 2; i <= n; ++i) {
        if (!is_prime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > n / i) { // 防止溢出并提前终止循环
                break;
            }
            is_prime[i * p] = true;
            if (i % p == 0) { // 保证每个合数被最小质因子筛除
                break;
            }
        }
    }
    return;
}
vector<int> ans;
void depos(int a, unordered_map<int, int> &num) {
    if (!is_prime[a]) {
        num[a]++;
        return;
    }
    for (int i = 0; primes[i] <= sqrt(a); i++) {
        while (a % primes[i] == 0) {
            num[primes[i]]++;
            a /= primes[i];
        }
    }
    if (a > 1)
        num[a]++;
    return;
}
void work() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> num;
    for (auto &i : a)
        cin >> i;
    if (n & 1) {
        cout << "YES" << endl;
        return;
    }
    if (n == 2) {
        if (a[0] == a[1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }
    for (auto &i : a) {
        depos(i, num);
    }
    for (auto &i : num) {
        if (i.second & 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    linearSieve(5e6+5);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}