#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
const int INF = 1e18;
const double PI = 3.14159265358979;
int n, k;
vector<vector<int>> tr(n + 1);
vector<int> us, ls, rs, father(n + 1);
vector<int> dp(n + 1);
void UP(int u, int son, int l, int r, int f) {
    if (!f)
        return;
    if (dp[u] == -1)
        UP(father[u], u, l, r, f);
    else {
        if (dp[u] >= r) {
            f = 0;
            return;
        }
        dp[son] = max(dp[u], l) + 1;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        s = '-' + s;
        int n = s.size() - 1;
        vector<pair<int, int>> consjt;
        if (s[1] != '>' || s[n] != '>') {
            cout << "No" << endl;
            continue;
        }
        int cnt = 0, f = 0, r = n;
        for (int i = n; i >= 1; i--) {
            if (s[i] == '>')
                cnt++;
            else {
                if (i <= n - 3) {
                    f = 1;
                }
                r = i + 3;
                break;
            }
        }
        if (cnt < 3)
            f = 0;
        if (!f) {
            cout << "No" << endl;
            continue;
        }
        vector<pair<int, int>> ans;
        vector<int> right;
        for (int i = n;; i -= 3) {
            int k = i;
            if (k < r)
                k = r;
            right.push_back(k);
            if (k == r)
                break;
        }
        for (int j = 0; j < right.size(); j++) {
            ans.push_back({1, right[j]});
        }
        for (int i = 2; i <= r - 4; i++) {
            if (s[i] == '>') {
                ans.push_back({i, r - i + 1});
            }
        }
        cout << "Yes " << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << ' ' << ans[i].second << endl;
            ;
        }
    }
    return 0;
}