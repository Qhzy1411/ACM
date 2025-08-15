// Author: QHZY
// Create_Time: 2025/08/14 14:11:39
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

/* ----- ----- ----- Segment Tree ----- ----- ----- */

struct Node {
    int max_val;
    int max_idx;
    int lazy;
};
vc<Node> tree;
void push_up(int rt) {
    if (tree[rt << 1].max_val >= tree[rt << 1 | 1].max_val) {
        tree[rt].max_val = tree[rt << 1].max_val;
        tree[rt].max_idx = tree[rt << 1].max_idx;
    } else {
        tree[rt].max_val = tree[rt << 1 | 1].max_val;
        tree[rt].max_idx = tree[rt << 1 | 1].max_idx;
    }
}
void push_down(int rt) {
    if (tree[rt].lazy != 0) {
        tree[rt << 1].max_val += tree[rt].lazy;
        tree[rt << 1].lazy += tree[rt].lazy;
        tree[rt << 1 | 1].max_val += tree[rt].lazy;
        tree[rt << 1 | 1].lazy += tree[rt].lazy;
        tree[rt].lazy = 0;
    }
}
void build(int l, int r, int rt) {
    tree[rt].lazy = 0;
    if (l == r) {
        tree[rt].max_val = 0;
        tree[rt].max_idx = l;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    push_up(rt);
}
void update(int L, int R, int val, int l, int r, int rt) {
    if (L > R)
        return;
    if (L <= l && r <= R) {
        tree[rt].max_val += val;
        tree[rt].lazy += val;
        return;
    }
    push_down(rt);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, val, l, m, rt << 1);
    if (R > m)
        update(L, R, val, m + 1, r, rt << 1 | 1);
    push_up(rt);
}
Node query(int L, int R, int l, int r, int rt) {
    if (L > R)
        return {-INF, -1, 0};
    if (L <= l && r <= R) {
        return tree[rt];
    }
    push_down(rt);
    int m = (l + r) >> 1;
    Node res1 = {-INF, -1, 0}, res2 = {-INF, -1, 0};
    if (L <= m)
        res1 = query(L, R, l, m, rt << 1);
    if (R > m)
        res2 = query(L, R, m + 1, r, rt << 1 | 1);
    if (res1.max_val >= res2.max_val)
        return res1;
    return res2;
}

/* ----- ----- ----- main ----- ----- ----- */

void init() {
}
void work() {
    int n;
    cin >> n;
    map<int, vi> poss;
    FOR(i, 1, n + 1) {
        int val;
        cin >> val;
        poss[val].eb(i);
    }
    tree.assign(n * 4 + 5, Node());
    build(1, n, 1);
    vvc<piii> events(n + 1);
    for (auto [val, pos] : poss) {
        if (size(pos) < 3)
            continue;
        int k = size(pos);
        int p1 = pos[0];
        int p2 = pos[1];
        int p3 = pos.back();
        if (p1 <= n - 2) {
            events[p1].eb(1, mp(p2 + 1, p3));
        }
        FOR(j, 1, k - 1) {
            int pj = pos[j];
            int pj1 = pos[j + 1];
            if (pj <= n - 2) {
                events[pj].eb(-1, mp(pj + 1, pj1));
            }
        }
    }
    int maxc = 0;
    int b1 = 2, b2 = 3;
    FOR(i, 1, n - 1) {
        for (auto event : events[i]) {
            int val = event.fi;
            int L = event.se.fi;
            int R = event.se.se;
            update(L, R, val, 1, n, 1);
        }
        if (i + 2 <= n) {
            Node res = query(i + 2, n, 1, n, 1);
            if (res.max_val > maxc) {
                maxc = res.max_val;
                b1 = i + 1;
                b2 = res.max_idx;
            }
        }
    }
    cout << maxc << endl;
    cout << b1 << " " << b2 << endl;
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