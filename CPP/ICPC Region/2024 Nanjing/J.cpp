// Author: QHZY
// Create_Time: 2025/08/06 14:31:19
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
    int n, m, k, a, b, ans = 0;
    cin >> n >> m >> k;
    vector<bool> fri(k + 1, false);
    vi contri(k + 1, 0);
    map<pii, int> mm;
    for (int i = 0; i < n; i++) {
        cin >> a;
        fri[a] = true;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (fri[a] && fri[b]) {
            ans++;
        } else if (fri[a]) {
            contri[b]++;
        } else if (fri[b]) {
            contri[a]++;
        } else {
            if (a == b) {
                contri[a]++;
            } else if (a > b) {
                mm[{b, a}]++;
            } else {
                mm[{a, b}]++;
            }
        }
    }
    int maxx = 0;
    for (auto [pp, cc] : mm) {
        int aa = pp.first;
        int bb = pp.second;
        maxx = max(maxx, cc + contri[aa] + contri[bb]);
    }
    sort(contri.rbegin(), contri.rend());
    maxx = max(maxx, contri[0] + contri[1]);
    ans += maxx;
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