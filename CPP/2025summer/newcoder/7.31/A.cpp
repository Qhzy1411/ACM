// Author: QHZY
// Create_Time: 2025/07/31 12:13:45
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

/* ----- ----- ----- main ----- ----- ----- */
const int MOD = 998244353;
const int N = 5e5 + 5;

int fact[N];
int inv[N];
int inv_2[N];
int inv_3[N];
int h[N];
int h_d2[N];
int h_d3[N];

void pre() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    for (int i = 1; i < N; i++) {
        inv_2[i] = 1LL * inv[i] * inv[i] % MOD;
        inv_3[i] = 1LL * inv_2[i] * inv[i] % MOD;
    }
    h[0] = 0;
    for (int i = 1; i < N; i++) {
        h[i] = (h[i - 1] + inv[i]) % MOD;
    }
    h_d2[0] = 0;
    for (int i = 1; i < N; i++) {
        h_d2[i] = (h_d2[i - 1] + inv_2[i]) % MOD;
    }
    h_d3[0] = 0;
    for (int i = 1; i < N; i++) {
        h_d3[i] = (h_d3[i - 1] + inv_3[i]) % MOD;
    }
}

void work() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    int h_2 = 1LL * h[n] * h[n] % MOD;
    int h_3 = 1LL * h_2 * h[n] % MOD;
    int sum = (h_3 + 3LL * h_2 % MOD) % MOD;
    sum = (sum + h[n]) % MOD;
    sum = (sum + (MOD - 3LL * h_d2[n] % MOD) % MOD) % MOD;
    sum = (sum + (MOD - 3LL * h[n] * h_d2[n] % MOD) % MOD) % MOD;
    sum = (sum + 2LL * h_d3[n] % MOD) % MOD;
    sum = 1LL * sum * fact[n] % MOD;
    cout << sum << endl;
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