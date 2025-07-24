// Author: QHZY
// Create_Time: 2025/07/23 16:06:30
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

const ll INF = 0x3f3f3f3f3f3f3f3f;

/* ----- ----- ----- main ----- ----- ----- */

const ll N = 2e5 + 5;
vvi fac(N + 1);
vi num(N + 1);
void init() {
    for (int i = 1; i <= sqrt(N) + 1; i++) {
        for (int j = i; j <= N; j += i) {
            fac[j].pb(i);
        }
    }
}
void work() {
    int n, q, p, v, count = 0;
    cin >> n >> q;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {
            for (auto k : fac[i]) {
                num[k]++;
            }
            count++;
        }
    }
    int ans = 0;
    for (auto i : num) {
        if (i == count)
            ans++;
    }
    cout << ans << endl;
    while (q--) {
        ans = 0;
        cin >> p >> v;
        if (a[p - 1] <= a[p] && p >= 2) {
            if (a[p - 1] > v) {
                for (auto k : fac[p - 1]) {
                    if (num[k] == count)
                        ans++;
                    num[k]++;
                }
                count++;
            }
        } else if (p >= 2) {
            if (a[p - 1] <= v) {
                count--;
                for (auto k : fac[p - 1]) {
                    num[k]--;
                    if (num[k] == count)
                        ans++;
                }
            }
        }
        if (a[p] <= a[p + 1] && p < n) {
            if (v > a[p + 1]) {
                for (auto k : fac[p]) {
                    if (num[k] == count)
                        ans++;
                    num[k]++;
                }
                count++;
            }
        } else if (p < n) {
            if (v <= a[p + 1]) {
                count--;
                for (auto k : fac[p]) {
                    num[k]--;
                    if (num[k] == count)
                        ans++;
                }
            }
        }
        a[p] = v;
        cout << ans << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int _ = 1;
    cin >> _;
    while (_--)
        work();
    return 0;
}