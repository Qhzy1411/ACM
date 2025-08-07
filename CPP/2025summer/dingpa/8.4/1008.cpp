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
#define eb emplace_back
#define fi first
#define se second

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 0x3f3f3f3f3f3f3f3f;

/* ----- ----- ----- main ----- ----- ----- */

void work() {
    int n, m, k;
    cin >> n >> m >> k;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (k >= m) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int col_max = 0;
            for (int i = 0; i < n; i++) {
                col_max = max(col_max, a[i][j]);
            }
            ans += col_max;
        }
        cout << ans << endl;
        return;
    }
    vi best(1 << m, 0);
    for (int i = 0; i < n; i++) {
        vi curr(1 << m, 0);
        for (int mask = 1; mask < (1 << m); mask++) {
            int lsb = __builtin_ctz(mask);
            int prev_mask = mask ^ (1 << lsb);
            curr[mask] = curr[prev_mask] + a[i][lsb];
        }
        for (int mask = 1; mask < (1 << m); mask++) {
            best[mask] = max(best[mask], curr[mask]);
        }
    }
    vvi dp(k + 1, vi(1 << m, 0));
    for (int i = 1; i <= k; i++) {
        for (int mask = 1; mask < (1 << m); mask++) {
            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ submask] + best[submask]);
            }
        }
    }
    cout << dp[k][(1 << m) - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        work();
    }
    return 0;
}