// Author: QHZY
// Create_Time: 2025/08/07 14:25:43
#include <bits/stdc++.h>
using namespace std;

void YES(bool t = 1) { cout << (t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << (t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << (t ? "yes" : "no"); }
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
// 2进制中1的个数的奇偶性(-1为奇数，1为偶)
i32 popcnt_sgn(i32 x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }
i32 popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
i32 popcnt_sgn(i64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
i32 popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
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

#define FOR0(a) for (ll _ = 0; _ < ll(a); _++)
#define FOR1(a) for (ll _ = 1; _ <= ll(a); _++)
#define FOR0_R(a) for (ll _ = (a) - 1; _ >= ll(0); _--)
#define FOR0_R(a) for (ll _ = (a); _ > ll(0); _--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) ll(x.size())
#define elif else if
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 0x3f3f3f3f3f3f3f3f;

/* ----- ----- ----- main ----- ----- ----- */
vector<int> num(10);
vector<vector<int>> state(22);
vector<int> visited(1 << 22);
int chuo;
void pre() {
    num[0] = (1 << 7) - 1 - (1 << 3);
    num[1] = (1 << 2) + (1 << 5);
    num[2] = (1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6);
    num[3] = (1) + (1 << 2) + (1 << 3) + (1 << 5) + (1 << 6);
    num[4] = (1 << 1) + (1 << 3) + (1 << 2) + (1 << 5);
    num[5] = (1) + (1 << 1) + (1 << 3) + (1 << 5) + (1 << 6);
    num[6] = (1 << 7) - 1 - (1 << 2);
    num[7] = (1) + (1 << 2) + (1 << 5);
    num[8] = (1 << 7) - 1;
    num[9] = (1 << 7) - 1 - (1 << 4);
    int total = (1 << 21);
    for (int i = 0; i < total; i++) {
        int te = i;
        int cnt = __builtin_popcount(i);
        state[cnt].eb(i);
    }
}
bool jud(int x, vi &xx, vi &sz, int m) {
    for (auto mark : state[x]) {
        chuo++;
        int i = 0;
        for (; i < (int)xx.size(); i++) {
            int temp = mark & sz[xx[i]];
            if (visited[temp] == chuo)
                break;
            visited[temp] = chuo;
        }
        if (i == xx.size())
            return 1;
    }
    return 0;
}
void work() {
    int n, m;
    cin >> n >> m;
    vi xx(n);
    vi sz(pow(10, m));
    for (int i = 0; i < n; i++) {
        cin >> xx[i];
        int te = xx[i];
        for (int j = 0; j < m; j++) {
            sz[xx[i]] = sz[xx[i]] << 7;
            sz[xx[i]] |= num[te % 10];
            te /= 10;
        }
    }
    int l = 0, r = 7 * m;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (jud(mid, xx, sz, m))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    int T = 1;
    cin >> T;
    while (T--)
        work();
    return 0;
}