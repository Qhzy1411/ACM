// Author: QHZY
// Create_Time: 2025/08/04 15:29:15
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
    vi p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vvi len_start(n);
    vi startlen(n + 1), endlen(n + 1);
    for (int i = 1; i <= n; i++) {
        if (p[i] - startlen[i - 1] == 1)
            startlen[i] = startlen[i - 1] + 1;
        else {
            startlen[i] = startlen[i - 1];
        }
    }
    endlen[n] = (p[n] == n ? 1 : 0);
    for (int i = n - 1; i > 0; i--) {
        if (p[i] + endlen[i + 1] == n)
            endlen[i] = endlen[i + 1] + 1;
        else {
            endlen[i] = endlen[i + 1];
        }
    }
    int maxl = 0, len = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] > pos[i - 1]) {
            len++;
        } else {
            len_start[len].pb(i - len);
            maxl = max(maxl, len);
            len = 1;
        }
    }
    len_start[len].pb(n - len + 1);
    maxl = max(maxl, len);
    if (count(len_start[maxl].begin(), len_start[maxl].end(), 1) ||
        count(len_start[maxl].begin(), len_start[maxl].end(), n - maxl + 1)) {
        cout << n - maxl + 1 << endl;
        return;
    }
    int ans = INF;
    for (auto i : len_start[maxl]) {
        ans = min(ans, n - maxl + 2 - startlen[pos[i]] - endlen[pos[i + maxl - 1]]);
    }
    cout << ans << endl;
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