// Author: QHZY
// Create_Time: 2025/08/07 23:34:03
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
const int N = 2e5 + 5;
vi segarr(N);
typedef struct node {
    int info1, info2;
    int lazy;
} Node;
Node tree[4 * N];
void build(int node, int start, int end) {
    if (start == end) {
        tree[node].info1 = segarr[start];
        tree[node].info2 = segarr[start];
        tree[node].lazy = 0;
    } else {
        int mid = (start + end) / 2;
        int left = 2 * node, right = 2 * node + 1;
        build(left, start, mid);
        build(right, mid + 1, end);
        tree[node].info1 = max(tree[left].info1, tree[right].info1);
        tree[node].info2 = min(tree[left].info2, tree[right].info2);
        tree[node].lazy = 0;
    }
}
int query1(int node, int start, int end, int L, int R) {
    if (start > R || end < L)
        return 0;
    if (tree[node].lazy != 0) {
        tree[node].info1 += tree[node].lazy;
        tree[node].info2 += tree[node].lazy;
        if (start != end) {
            tree[2 * node].lazy += tree[node].lazy;
            tree[2 * node + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
    if (start >= L && end <= R)
        return tree[node].info1;
    int mid = (start + end) / 2;
    int left_sum = query1(2 * node, start, mid, L, R);
    int right_sum = query1(2 * node + 1, mid + 1, end, L, R);
    return max(left_sum, right_sum);
}
int query2(int node, int start, int end, int L, int R) {
    if (start > R || end < L)
        return 1e9;
    if (tree[node].lazy != 0) {
        tree[node].info1 += tree[node].lazy;
        tree[node].info2 += tree[node].lazy;
        if (start != end) {
            tree[2 * node].lazy += tree[node].lazy;
            tree[2 * node + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
    if (start >= L && end <= R)
        return tree[node].info2;
    int mid = (start + end) / 2;
    int left_sum = query2(2 * node, start, mid, L, R);
    int right_sum = query2(2 * node + 1, mid + 1, end, L, R);
    return min(left_sum, right_sum);
}
void update(int node, int start, int end, int idx, int new_value) {
    if (start == end) {
        tree[node].info1 = new_value;
        tree[node].info2 = new_value;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, new_value);
        else
            update(2 * node + 1, mid + 1, end, idx, new_value);
        tree[node].info1 = max(tree[2 * node].info1, tree[2 * node + 1].info1);
        tree[node].info2 = min(tree[2 * node].info2, tree[2 * node + 1].info2);
    }
}
void range_update(int node, int start, int end, int L, int R, int val) {
    if (tree[node].lazy != 0) {
        tree[node].info1 += tree[node].lazy;
        tree[node].info2 += tree[node].lazy;
        if (start != end) {
            tree[2 * node].lazy += tree[node].lazy;
            tree[2 * node + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
    if (start > R || end < L)
        return;
    if (start >= L && end <= R) {
        tree[node].info1 += val;
        tree[node].info2 += val;
        if (start != end) {
            tree[2 * node].lazy += val;
            tree[2 * node + 1].lazy += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    range_update(2 * node, start, mid, L, R, val);
    range_update(2 * node + 1, mid + 1, end, L, R, val);
    tree[node].info1 = max(tree[2 * node].info1, tree[2 * node + 1].info1);
    tree[node].info2 = min(tree[2 * node].info2, tree[2 * node + 1].info2);
}
void init() {
}
void work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    FOR(i, n)
    cin >> a[i];
    FOR(i, n)
    cin >> b[i];
    int sum = 0;
    FOR(i, n) {
        if (a[i] > b[i])
            swap(a[i], b[i]);
        sum += b[i] - a[i];
    }
    vc<pii> dis(n);
    FOR(i, n) {
        dis[i].fi = a[i];
        dis[i].se = b[i];
    }
    sort(dis.begin(), dis.end());
    bool flag = false;
    FOR(i, n - 1) {
        if (dis[i].se >= dis[i + 1].fi) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << sum << endl;
        return;
    }
    FOR(i, n) {
        int x = dis[i].fi, y = dis[i].se;
        segarr[i] = x + y + abs(x - y);
    }
    build(1, 0, n - 1);
    int minchange = INF;
    FOR(i, 1, n) {
        int x = dis[i].fi, y = dis[i].se;
        int change = -query1(1, 0, n - 1, 0, i - 1) + x + y - abs(x - y);
        minchange = min(minchange, change);
    }
    cout << sum + minchange << endl;
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