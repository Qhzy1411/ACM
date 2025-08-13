// Author: QHZY
// Create_Time: 2025/08/12 15:18:02
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
using vvi = vector<vi>;
using vvvi = vector<vvi>;
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

const int MOD = 998244353;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool run(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
int getday(int y, int m) {
    if (m == 2 && run(y))
        return 29;
    return days[m - 1];
}
void work() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    vi dp1(10);
    vi dp2(100);
    vi dp3(1000);
    vi dp4(2); // 1 为闰年，0 非闰年
    vvi dp5(2, vi(2));
    vvi dp6(2, vi(13));
    vvvi dp7(2, vvi(13, vi(4)));
    for (char sc : s) {
        int c = sc - '0';
        FOR(y, 2) {
            FOR(m, 1, 13) {
                FOR(d1, 4) {
                    if (dp7[y][m][d1] == 0)
                        continue;
                    int d = d1 * 10 + c;
                    if (d >= 1 && d <= getday((y == 1) ? 4 : 1, m)) {
                        ans = (ans + dp7[y][m][d1]) % MOD;
                    }
                }
            }
        }
        FOR(y, 2) {
            FOR(m, 1, 13) {
                if (dp6[y][m] == 0)
                    continue;
                if ((c >= 0 && c <= 2) || (c == 3 && m != 2)) {
                    dp7[y][m][c] = (dp7[y][m][c] + dp6[y][m]) % MOD;
                }
            }
        }
        FOR(y, 2) {
            FOR(m1, 2) {
                if (dp5[y][m1] == 0)
                    continue;
                int m = m1 * 10 + c;
                if (m >= 1 && m <= 12) {
                    dp6[y][m] = (dp6[y][m] + dp5[y][m1]) % MOD;
                }
            }
        }
        FOR(y, 2) {
            if (dp4[y] == 0)
                continue;
            if (c <= 1) {
                dp5[y][c] = (dp5[y][c] + dp4[y]) % MOD;
            }
        }
        FOR(y3, 1000) {
            if (dp3[y3] == 0)
                continue;
            if (y3 == 0 && c == 0)
                continue;
            int y = run((y3 * 10 + c) % 400) ? 1 : 0;
            dp4[y] = (dp4[y] + dp3[y3]) % MOD;
        }
        FOR(y2, 100) {
            if (dp2[y2] == 0)
                continue;
            dp3[y2 * 10 + c] = (dp3[y2 * 10 + c] + dp2[y2]) % MOD;
        }
        FOR(y1, 10) {
            if (dp1[y1] == 0)
                continue;
            dp2[y1 * 10 + c] = (dp2[y1 * 10 + c] + dp1[y1]) % MOD;
        }
        dp1[c] = (dp1[c] + 1) % MOD;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        work();
    return 0;
}