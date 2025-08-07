#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int mod = 1e9 + 7;
ll qmi(ll a, ll b, ll p) {
    ll res = 1;
    while (b != 0) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll p) {
    return qmi(a, p - 2, p);
}
void work() {
    int n, k;
    cin >> n >> k;
    cout << k * inv(n - k + 1, mod) % mod << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}