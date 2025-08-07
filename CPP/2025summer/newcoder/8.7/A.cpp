// Author: QHZY
// Create_Time: 2025/08/07 12:01:31
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
    string s;
    cin >> s;
    vi x;
    bool fu = false;
    for (int i : s) {
        if (i == '-') {
            fu = true;
            continue;
        }
        x.pb(i - '0');
    }
    bool dole = false;
    if (!fu) {
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != 0 && !dole)
                cout << x[i];
            else if (!dole) {
                cout << 1 << x[i];
                dole = true;
            } else {
                cout << x[i];
            }
        }
        if (!dole) {
            cout << 1 << endl;
        } else {
            cout << endl;
        }
    } else {
        cout << '-';
        for (int i = 0; i < x.size(); i++) {
            if ((x[i] == 0 || x[i] == 1) && !dole) {
                cout << x[i];
            } else if (!dole) {
                cout << 1 << x[i];
                dole = true;
            } else {
                cout << x[i];
            }
        }
        if (!dole) {
            cout << 1 << endl;
        } else {
            cout << endl;
        }
    }
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