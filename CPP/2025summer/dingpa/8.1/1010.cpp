// Author: QHZY
// Create_Time: 2025/08/01 13:20:13
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

/* ----- ----- ----- main ----- ----- ----- */

void work() {
    int n;
    cin >> n;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    vector<double> exp(n + 1);
    double hou_min = 99999999999999;
    for (int i = n; i >= 1; i--) {
        exp[i] = (1.0 - x[i] / 1000.0) * i + x[i] / 1000.0 * (hou_min + 20);
        hou_min = min(hou_min, exp[i]);
    }
    cout << fixed << setprecision(10) << hou_min << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        work();
    return 0;
}