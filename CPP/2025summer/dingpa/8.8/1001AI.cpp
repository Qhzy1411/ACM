// Author: QHZY
// Create_Time: 2025/08/08 16:56:43
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
#define int ll
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

#define FOR1(a) for (ll _ = 0; _ < ll(a); _++)
#define FOR2(i, a) for (ll i = 0; i < ll(a); i++)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); i++)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll _ = (a) - 1; _ >= ll(0); _--)
#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0); i--)
#define FOR3_R(i, a, b) for (ll i = (a) - 1; i >= ll(b); i--)
#define FOR4_R(i, a, b, c) for (ll i = (a) - 1; i >= ll(b); i -= (c))
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

/* ----- ----- ----- main ----- ----- ----- */

void init() {
}
struct Point {
    int x, y, v;
};
int solve_1d(const vi &a, int W, int n_coords) {
    if (W <= 0) {
        return 0;
    }
    vi pre(n_coords + 1, 0);
    for (int i = 0; i < n_coords; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    int maxsum = 0;
    deque<int> dq;
    dq.pb(0);
    for (int i = 1; i <= n_coords; i++) {
        if (!dq.empty() && dq.front() < i - W) {
            dq.pop_front();
        }
        if (!dq.empty()) {
            maxsum = max(maxsum, pre[i] - pre[dq.front()]);
        }
        while (!dq.empty() && pre[dq.back()] >= pre[i]) {
            dq.pop_back();
        }
        dq.pb(i);
    }
    return maxsum;
}
void work() {
    int n;
    int k;
    cin >> n >> k;
    map<pii, int> point_map;
    for (int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        point_map[{x, y}] += v;
    }
    vc<Point> points;
    vi all_x, all_y;
    for (auto const &[coord, val] : point_map) {
        points.pb({coord.first, coord.second, val});
        all_x.pb(coord.first);
        all_y.pb(coord.second);
    }
    sort(all_x.begin(), all_x.end());
    all_x.erase(unique(all_x.begin(), all_x.end()), all_x.end());
    sort(all_y.begin(), all_y.end());
    all_y.erase(unique(all_y.begin(), all_y.end()), all_y.end());
    int nx = size(all_x);
    int ny = size(all_y);
    vvc<pii> points_by_y(ny);
    for (const auto &p : points) {
        int x_idx = lower_bound(all_x.begin(), all_x.end(), p.x) - all_x.begin();
        int y_idx = lower_bound(all_y.begin(), all_y.end(), p.y) - all_y.begin();
        points_by_y[y_idx].pb({x_idx, p.v});
    }
    int ans = 0;
    for (int i = 0; i < ny; i++) {
        vi col_sum(nx, 0);
        for (int j = i; j < ny; j++) {
            for (const auto &p : points_by_y[j]) {
                col_sum[p.first] += p.second;
            }
            int height = all_y[j] - all_y[i] + 1;
            if (height > k)
                continue;
            int max_width = k / height;
            ans = max(ans, solve_1d(col_sum, max_width, nx));
        }
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