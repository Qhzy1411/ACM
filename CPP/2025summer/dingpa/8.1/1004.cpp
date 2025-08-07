// Author: QHZY
// Create_Time: 2025/08/01 13:12:49
#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using f128 = long double;

using ll = long long;
#define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld

using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using piii = pair<int, pii>;

#define pb push_back
#define eb emplace_back;
#define fi first
#define se second

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
/* ----- ----- ----- main ----- ----- ----- */
vector<ll> fact(N + 1);
void pre() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
}
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
void work() {
    int n, m;
    cin >> n >> m;
    vi q(n), k(m);
    for (int i = 0; i < n; i++)
        cin >> q[i];
    for (int i = 0; i < m; i++) {
        cin >> k[i];
    }
    ll ans = qmi(fact[n], m, MOD);
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    int _ = 1;
    cin >> _;
    while (_--)
        work();
    return 0;
}