// Author: QHZY
// Create_Time: 2025/07/31 15:26:28
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
void get_yinzi(int n, vi &yinzi) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            yinzi.push_back(i);
            if (i * i != n) {
                yinzi.push_back(n / i);
            }
        }
    }
}
bool judge(int n, vi &a) {
    int front = -1, back = a.size();
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % n == 0)
            front++;
        else
            break;
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] % n == 0)
            back--;
        else
            break;
    }
    if (front >= back - 1)
        return true;
    for (int i = front + 2; i < back; i++) {
        if (abs(a[i] - a[i - 1]) % n != 0)
            return false;
    }
    return true;
}
void work() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool equal = true;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1])
            equal = false;
    }
    if (equal) {
        cout << 0 << endl;
        return;
    }
    vi poss;
    get_yinzi(a[0], poss);
    get_yinzi(a[n - 1], poss);
    int middlegcd = abs(a[1] - a[0]);
    for (int i = 2; i < n; i++) {
        if (middlegcd == 1) {
            break;
        }
        if (a[i] - a[i - 1] != 0)
            middlegcd = __gcd(middlegcd, abs(a[i] - a[i - 1]));
    }
    poss.pb(middlegcd);
    sort(poss.rbegin(), poss.rend());
    int ans = 1;
    for (int i = 0; i < poss.size(); i++) {
        if (i > 0 && poss[i] == poss[i - 1])
            continue;
        if (judge(poss[i], a)) {
            ans = poss[i];
            break;
        }
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