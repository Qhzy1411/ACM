#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
const int INF = 1e18;
const double PI = 3.1415926535897932;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        int maxai = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            maxai = max(maxai, a[i]);
        }
        vector<vector<vector<vector<pair<int, int>>>>> dp(2, vector<vector<vector<pair<int, int>>>>(151, vector<vector<pair<int, int>>>(151, vector<pair<int, int>>(2))));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 150; j++) {
                for (int k = j; k <= 150; k++) {
                    if (j < a[i] && k < a[i]) {
                        dp[1][j][k][0].first = INF;
                        dp[1][j][k][0].second = INF;
                        dp[1][j][k][1].first = INF;
                        dp[1][j][k][1].second = INF;
                    } else if (j < a[i] && k >= a[i]) {
                        dp[1][j][k][0].first = INF;
                        dp[1][j][k][0].second = INF;
                        dp[1][j][k][1].second = k - a[i];
                        dp[1][j][k][1].first = min(dp[0][j][k][0].first + max(0LL, dp[1][j][k][1].second - dp[0][j][k][0].second), dp[0][j][k][1].first + max(0LL, dp[1][j][k][1].second - dp[0][j][k][1].second));
                    } else {
                        int temp1 = j - a[i], temp2 = k - a[i];
                        dp[1][j][k][0].first = min(max(temp1 - dp[0][j][k][0].second, 0LL) + dp[0][j][k][0].first, max(temp1 - dp[0][j][k][1].second, 0LL) + dp[0][j][k][1].first);
                        dp[1][j][k][0].second = temp1;
                        dp[1][j][k][1].first = min(max(temp2 - dp[0][j][k][0].second, 0LL) + dp[0][j][k][0].first, max(temp2 - dp[0][j][k][1].second, 0LL) + dp[0][j][k][1].first);
                        dp[1][j][k][1].second = temp2;
                    }
                    dp[0][j][k][0].first = dp[1][j][k][0].first;
                    dp[0][j][k][0].second = dp[1][j][k][0].second;
                    dp[0][j][k][1].first = dp[1][j][k][1].first;
                    dp[0][j][k][1].second = dp[1][j][k][1].second;
                }
            }
        }
        int ans = 1e9;
        if (m == 2) {
            for (int x = 0; x <= 150; x++) {
                for (int y = x; y <= 150; y++) {
                    int k = 0;
                    k = min(dp[1][x][y][0].first, dp[1][x][y][1].first);
                    ans = min(ans, k);
                }
            }
        } else {
            for (int x = 0; x <= 150; x++) {
                ans = min(ans, dp[1][x][x][1].first);
            }
        }
        cout << ans << endl;
    }
    return 0;
}