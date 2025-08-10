#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
template <class T>
using vc = vector<T>;

// 线性筛  时间：O(n)
const ll N = 1e6 + 5;

vi primes;
vc<bool> not_prime(N, 0);
void Linear(int n) {
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            primes.push_back(i);
        }
        for (int pri_j : primes) {
            if (i * pri_j > n)
                break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) {
                break;
            }
        }
    }
}