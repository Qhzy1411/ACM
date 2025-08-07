// Author: QHZY
// Create_Time: 2025/07/29 12:05:40
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

/* ----- ----- ----- main ----- ----- ----- */

void work() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 4 << endl;
        return;
    }
    if (n == 2) {
        cout << 8 << endl;
        return;
    }
    if (n & 1) {
        cout << 3 * n + 1 << endl;
    } else {
        cout << 3 * n + 2 << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        work();
    return 0;
}