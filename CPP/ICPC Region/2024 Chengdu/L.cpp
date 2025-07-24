// Author: QHZY
// Create_Time: 2025/07/23 13:37:21
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

const ll INF = 0x3f3f3f3f3f3f3f3f;

/* ----- ----- ----- main ----- ----- ----- */

void work() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << 100 << endl;
    for (int i = 1; i <= 49; i++) {
        cout << 1 << ' ';
    }
    cout << a << ' ';
    for (int i = 51; i <= 94; i++) {
        cout << a + 1 << ' ';
    }
    cout << b << ' ';
    for (int i = 96; i <= 98; i++) {
        cout << b + 1 << ' ';
    }
    cout << c << ' ' << c + 1 << endl;
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