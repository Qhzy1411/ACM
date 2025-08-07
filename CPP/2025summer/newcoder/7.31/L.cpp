// Author: QHZY
// Create_Time: 2025/07/31 13:07:03
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
bool cmp(const pii &a, const pii &b) {
    return a.first > b.first;
}
void work() {
    int n, m;
    cin >> n >> m;
    vector<pii> lr(m);
    for (int i = 0; i < m; i++) {
        cin >> lr[i].first >> lr[i].second;
    }
    sort(lr.begin(), lr.end(), cmp);
    vector<char> ans(2 * n, ')');
    int last = 0, cnt = 0;
    for (auto &[l, r] : lr) {
        if (last >= l && last <= r)
            continue;
        int pos = l;
        if (pos > r) {
            cout << -1 << endl;
            return;
        }
        ans[pos - 1] = '(';
        cnt++;
        last = pos;
        if (cnt > n) {
            cout << -1 << endl;
            return;
        }
    }
    int rem = n - cnt;
    if (rem < 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < 2 * n && rem > 0; i++) {
        if (ans[i] == ')') {
            ans[i] = '(';
            rem--;
        }
    }
    int match = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (ans[i] == '(')
            match++;
        else
            match--;
        if (match < 0) {
            cout << -1 << endl;
            return;
        }
    }
    if (match != 0) {
        cout << -1 << endl;
        return;
    }
    vi pre(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        pre[i] = pre[i - 1] + (ans[i - 1] == '(' ? 1 : 0);
    }
    for (auto &[l, r] : lr) {
        if (pre[r] - pre[l - 1] == 0) {
            cout << -1 << endl;
            return;
        }
    }
    for (char c : ans)
        cout << c;
    cout << endl;
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