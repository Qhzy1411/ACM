#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 取模快速幂  时间：O(log n)
inline ll qmi(ll base, ll exp, ll mod) {
    // 当mod为质数时使用费马小定理优化快速幂
    /*
    exp %= mod - 1;
    if (exp == 0) {
        exp = mod - 1;
    }
    */
    ll res = 1;
    while (exp != 0) {
        if (exp & 1)
            res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}