// Author: QHZY
// Create_Time: 2025/08/08 13:27:57
#include <bits/stdc++.h>
using namespace std;

void YES(bool t = 1) { cout << (t ? "YES\n" : "NO\n"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << (t ? "Yes\n" : "No\n"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << (t ? "yes\n" : "no\n"); }
void no(bool t = 1) { yes(!t); }

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using f128 = long double;

// 2进制中1的个数
i32 popcnt(i32 x) { return __builtin_popcount(x); }
i32 popcnt(u32 x) { return __builtin_popcount(x); }
i32 popcnt(i64 x) { return __builtin_popcountll(x); }
i32 popcnt(u64 x) { return __builtin_popcountll(x); }
// 2进制中1的个数的奇偶性(1为奇数，0为偶)
i32 popcnt_sgn(i32 x) { return (__builtin_parity(u32(x)) & 1 ? 1 : 0); }
i32 popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? 1 : 0); }
i32 popcnt_sgn(i64 x) { return (__builtin_parityll(u64(x)) & 1 ? 1 : 0); }
i32 popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? 1 : 0); }
// 2进制中1的最高有效位 (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
i32 topbit(i32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
i32 topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
i32 topbit(i64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
i32 topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// 2进制中1的最低有效位 (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
i32 lowbit(i32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
i32 lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
i32 lowbit(i64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
i32 lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

using ll = long long;
// #define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld

using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using piii = pair<int, pii>;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define FOR1(a) for (int _ = 0; _ < int(a); _++)
#define FOR2(i, a) for (int i = 0; i < int(a); i++)
#define FOR3(i, a, b) for (int i = a; i < int(b); i++)
#define FOR4(i, a, b, c) for (int i = a; i < int(b); i += (c))
#define FOR1_R(a) for (int _ = (a) - 1; _ >= int(0); _--)
#define FOR2_R(i, a) for (int i = (a) - 1; i >= int(0); i--)
#define FOR3_R(i, a, b) for (int i = (a) - 1; i >= int(b); i--)
#define FOR4_R(i, a, b, c) for (int i = (a) - 1; i >= int(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define size(x) ll(x.size())

#define elif else if
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e4 + 10;
/* ----- ----- ----- main ----- ----- ----- */
int pre[N][N];
bool vis[N][N];
void init() {
}
void work() {
    int n, k;
    cin >> n >> k;
    vc<pii> help_vis;
    vc<bool> x_h(n + 1), y_h(n + 1);
    vi x_poss, y_poss;
    FOR(i, n) {
        int x, y, v;
        cin >> x >> y >> v;
        if (!x_h[x]) {
            x_h[x] = 1;
            x_poss.eb(x);
        }
        if (!y_h[x]) {
            y_h[x] = 1;
            y_poss.eb(x);
        }
        if (!vis[x][y]) {
            pre[x][y] = v;
            vis[x][y] = 1;
            help_vis.eb(mp(x, y));
        } else {
            pre[x][y] += v;
        }
    }
    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            if (vis[i][j])
                pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            else
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    vi k_yinzi;
    for (int i = 1; i * i <= k && i <= n; i++) {
        if (k % i == 0) {
            if (k / i <= n) {
                k_yinzi.eb(i), k_yinzi.eb(k / i);
            } else {
                k_yinzi.eb(i);
            }
        }
    }
    int ans = 0;
    sort(all(x_poss));
    sort(all(y_poss));
    for (auto w : k_yinzi) {
        int h = min(n, k / w);
        int maxa = n - w + 1;
        int maxc = n - h + 1;
        if (maxa < 1 || maxc < 1)
            continue;
        for (auto &a : x_poss) {
            if (a > maxa)
                break;
            for (auto &c : y_poss) {
                if (c > maxc)
                    break;
                int b = a + w - 1;
                int d = c + h - 1;
                int curr = pre[b][d] - pre[a - 1][d] - pre[b][c - 1] + pre[a - 1][c - 1];
                if (curr > ans) {
                    ans = curr;
                }
            }
        }
    }
    for (auto [x, y] : help_vis) {
        vis[x][y] = 0;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        work();
    return 0;
}