#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

using ll = long long;
// #define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld

using vi = vector<ll>;
using vvi = vector<vector<ll>>;
using pii = pair<ll, ll>;
using piii = pair<ll, pii>;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 0x3f3f3f3f3f3f3f3f;

/* ----- ----- ----- main ----- ----- ----- */

const u32 U = (1u << 30) - 1;
class F {
public:
    u32 f__3, f__2, f__1;
    F(int a, int b, int c) {
        f__3 = (u32)(a & U);
        f__2 = (u32)(b & U);
        f__1 = (u32)(c & U);
    }
    u32 next() {
        u32 g = f__3 ^ ((f__3 << 16) & U);
        u32 h = g ^ (g >> 5);
        u32 f = h ^ ((h << 1) & U) ^ f__2 ^ f__1;
        f__3 = f__2;
        f__2 = f__1;
        f__1 = f;
        return f;
    }
};
void work() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    F gen(a, b, c);
    int jiou = 0; // 奇偶性
    for (int i = 0; i < n; i++) {
        u32 f = gen.next();
        if (n - i > 1) {
            if ((f % (n - i)) != 0) {
                jiou ^= 1;
            }
        }
    }
    cout << jiou;
    for (int i = 1; i < n; i++) {
        u32 f1 = gen.next();
        u32 f2 = gen.next();
        u32 f3 = gen.next();
        int v1 = f1 % n;
        int v2 = f2 % n;
        int l = min(v1, v2);
        int r = max(v1, v2);
        int d = (f3 % n) + 1;
        int m = r - l + 1;
        if ((d & 1) && !(m & 1)) {
            jiou ^= 1;
        }
        cout << jiou;
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        work();
    return 0;
}