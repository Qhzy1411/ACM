// Author: QHZY
// Create_Time: 2025/08/11 14:19:16
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

const int S = 8;
struct Matrix {
    int mat[S][S];
    Matrix() {
        FOR2(i, S)
        FOR2(j, S)
        mat[i][j] = -INF;
    }
};
Matrix operator*(const Matrix &aa, const Matrix &bb) {
    Matrix cc;
    FOR2(i, S) {
        FOR2(j, S) {
            if ((i & 1) != ((j >> 2) & 1))
                continue;
            int k = ((i >> 1) & 1) * 4 + (i & 1) * 2 + ((j >> 1) & 1);
            if (aa.mat[i][k] != -INF && bb.mat[k][j] != -INF) {
                cc.mat[i][j] = aa.mat[i][k] + bb.mat[k][j];
            }
        }
    }
    return cc;
}
int n, q;
vi a;
vc<Matrix> seg;
void init() {
}
Matrix build_leaf(int val1, int val2) {
    Matrix M1, M2;
    FOR(s, S) {
        FOR(i, 2) {
            if (i == 1 && s == 7)
                continue;
            int ss = (i << 2) | ((s >> 1) & 3);
            M1.mat[ss][s] = max(M1.mat[ss][s], (i == 1 ? val1 : 0LL));
        }
    }
    FOR(s, S) {
        FOR(i, 2) {
            if (i == 1 && s == 7)
                continue;
            int ss = (i << 2) | ((s >> 1) & 3);
            M2.mat[ss][s] = max(M2.mat[ss][s], (i == 1 ? val2 : 0LL));
        }
    }
    return M2 * M1;
}
Matrix build_single_leaf(int val) {
    Matrix M;
    FOR(s, S) {
        FOR(i, 2) {
            if (i == 1 && s == 7)
                continue;
            int ss = (i << 2) | (s >> 1);
            M.mat[ss][s] = max(M.mat[ss][s], (i == 1 ? val : 0LL));
        }
    }
    return M;
}
Matrix multiply_slow(const Matrix &aa, const Matrix &bb) {
    Matrix cc;
    FOR(i, S) {
        FOR(k, S) {
            if (aa.mat[i][k] == -INF)
                continue;
            FOR(j, S) {
                if (bb.mat[k][j] != -INF) {
                    cc.mat[i][j] = max(cc.mat[i][j], aa.mat[i][k] + bb.mat[k][j]);
                }
            }
        }
    }
    return cc;
}
void build(int p, int l, int r) {
    if (l == r) {
        seg[p] = build_single_leaf(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    seg[p] = multiply_slow(seg[p * 2 + 1], seg[p * 2]);
}
void update(int p, int l, int r, int x, int v) {
    if (l == r) {
        seg[p] = build_single_leaf(v);
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid) {
        update(p * 2, l, mid, x, v);
    } else {
        update(p * 2 + 1, mid + 1, r, x, v);
    }
    seg[p] = multiply_slow(seg[p * 2 + 1], seg[p * 2]);
}
void solve() {
    Matrix total = seg[1];
    int ans = 0;
    FOR(i, S) {
        ans = max(ans, total.mat[i][i]);
    }
    cout << ans << endl;
}
void work() {
    cin >> n >> q;
    a.assign(n + 1, 0);
    seg.assign(4 * n + 5, Matrix());
    FOR(i, 1, n + 1)
    cin >> a[i];
    build(1, 1, n);
    solve();
    FOR(i, q) {
        int x, v;
        cin >> x >> v;
        a[x] = v;
        update(1, 1, n, x, v);
        solve();
    }
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