// Author: QHZY
// Create_Time: 2025/07/25 12:06:54
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
    int n, m, mini = 0, maxi = 0;
    cin >> n >> m;
    vi b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (i > 0) {
            b[i] = max(b[i - 1], b[i]);
        }
        mini += b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    maxi = c[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        c[i] = min(c[i + 1], c[i]);
        maxi += c[i];
    }
    if (m >= mini && m <= maxi)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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