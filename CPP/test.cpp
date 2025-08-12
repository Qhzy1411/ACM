// Author: QHZY
// Create_Time: 2025/08/08 01:09:42
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
// AC自动机 时间：O(n)
constexpr int N = 1e6 + 6;    // 模式串个数
constexpr int LEN = 1e6 + 6;  // 文本串长度
constexpr int SIZE = 1e6 + 6; // 模式串长度总和
namespace AC {
    struct Node {
        int son[26];
        int ans;
        int fail;
        int idx;

        void init() {
            memset(son, 0, sizeof(son));
            ans = idx = fail = 0;
        }
    } tr[SIZE];

    int tot;
    int ans[N], pidx;

    vi g[SIZE]; // fail 树

    void init() {
        for (int i = 0; i <= tot; i++) {
            g[i].clear();
            tr[i].init();
        }
        tot = pidx = 0;
        memset(ans, 0, sizeof(ans));
    }

    void insert(string s, int &idx) {
        int u = 0;
        for (int i = 0; s[i]; i++) {
            int &son = tr[u].son[s[i] - 'a'];
            if (!son)
                son = ++tot, tr[son].init();
            u = son;
        }
        // 由于有可能出现相同的模式串，需要将相同的映射到同一个编号
        if (!tr[u].idx)
            tr[u].idx = ++pidx; // 第一次出现，新增编号
        idx = tr[u].idx;        // 这个模式串的编号对应这个结点的编号
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++)
            if (tr[0].son[i]) {
                q.push(tr[0].son[i]);
                g[0].push_back(tr[0].son[i]); // 不要忘记这里的 fail
            }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (tr[u].son[i]) {
                    tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                    g[tr[tr[u].fail].son[i]].push_back(tr[u].son[i]); // 记录 fail 树
                    q.push(tr[u].son[i]);
                } else
                    tr[u].son[i] = tr[tr[u].fail].son[i];
            }
        }
    }

    void query(string t) {
        int u = 0;
        for (int i = 0; t[i]; i++) {
            u = tr[u].son[t[i] - 'a'];
            tr[u].ans++;
        }
    }

    void dfs(int u) {
        for (int v : g[u]) {
            dfs(v);
            tr[u].ans += tr[v].ans;
        }
        ans[tr[u].idx] = tr[u].ans;
    }
} // namespace AC
void init() {
}
void work() {
    int n;
    cin >> n;
    vi idx(n);
    string s;
    for (int i = 0; i < n; i++) { // 插入n个模式串
        cin >> s;
        AC::insert(s, idx[i]);
        AC::ans[i] = 0;
    }
    AC::build();
    cin >> s;
    AC::query(s); // 目标串查询、DFS
    AC::dfs(0);
    int ans = 0;
    FOR(i, n) {
        if (AC::ans[idx[i]])
            ans++;
    }
    cout << ans << endl;
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    // cin >> T;
    while (T--)
        work();
    return 0;
}