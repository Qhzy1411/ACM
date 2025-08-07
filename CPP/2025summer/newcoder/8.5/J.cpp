// Author: QHZY
// Create_Time: 2025/08/05 13:22:05
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
/* ----- ----- ----- main ----- ----- ----- */

inline ll qmi(ll a, ll b) {
    b %= mod - 1;
    if (b == 0) {
        b = mod - 1;
    }
    int res = 1;
    a %= mod;
    while (b != 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int g(int a, int b, int c, int d) {
    int ans = 1;
    int gc = __gcd(a, c);
    if (gc == 1)
        return ans;
    ans = ans * qmi(gc, min(b, d)) % mod;
    if (b > d) {
        ans = ans * g(a, b - d, c / gc, d) % mod;
    } else if (b < d) {
        ans = ans * g(a / gc, b, c, d - b) % mod;
    }
    return ans;
}
void work() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << g(a, b, c, d) << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}