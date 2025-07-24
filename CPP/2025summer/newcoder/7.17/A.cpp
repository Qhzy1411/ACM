// Author: QHZY
// Create_Time: 2025/07/17 12:34:20
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
#define int ll
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 5e5 + 10;
const ll MOD = 998244353;
int pow2[MOD];
void precompute() {
    pow2[0] = 1;
    for (int i = 1; i < MOD; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
}
void work() {
    int n, k = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == -1) {
            k++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            continue;
        } else if (a[i] == 1) {
            if (i == 0) {
                ans = (ans + pow2[k]) % MOD;
            } else {
                if (a[i - 1] == 0) {
                    ans = (ans + pow2[k]) % MOD;
                } else if (a[i - 1] == -1) {
                    ans = (ans + pow2[k - 1]) % MOD;
                }
            }
        } else {
            if (i == 0) {
                ans = (ans + pow2[k - 1]) % MOD;
            } else {
                if (a[i - 1] == 0) {
                    ans = (ans + pow2[k - 1]) % MOD;
                } else if (a[i - 1] == -1) {
                    ans = (ans + pow2[k - 2]) % MOD;
                }
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    precompute();
    while (_--)
        work();
    return 0;
}