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
        vector<vector<vector<pair<int, int>>>> dp(n + 1, vector<vector<pair<int, int>>>(maxai + 1, vector<pair<int, int>>(2)));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= maxai; j++) {
                if (j < a[i]) {
                    dp[i][j][0].first = INF;
                    dp[i][j][0].second = INF;
                    dp[i][j][1].second = maxai - a[i];
                    dp[i][j][1].first = min(dp[i - 1][j][0].first + max(0LL, dp[i][j][1].second - dp[i - 1][j][0].second), dp[i - 1][j][1].first + max(0LL, dp[i][j][1].second - dp[i - 1][j][1].second));
                } else {
                    int temp1 = j - a[i], temp2 = maxai - a[i];
                    dp[i][j][0].first = min(max(temp1 - dp[i - 1][j][0].second, 0LL) + dp[i - 1][j][0].first, max(temp1 - dp[i - 1][j][1].second, 0LL) + dp[i - 1][j][1].first);
                    dp[i][j][0].second = temp1;
                    dp[i][j][1].first = min(max(temp2 - dp[i - 1][j][0].second, 0LL) + dp[i - 1][j][0].first, max(temp2 - dp[i - 1][j][1].second, 0LL) + dp[i - 1][j][1].first);
                    dp[i][j][1].second = temp2;
                }
            }
        }

        int ans = 1e9;
        if (m == 2) {
            for (int x = 0; x <= maxai; x++) {
                int k = 0;
                k = min(dp[n][x][0].first, dp[n][x][1].first);
                ans = min(ans, k);
            }
        } else {
            int k = 0;
            k = dp[n][maxai][1].first;
            ans = min(ans, k);
        }
        cout << ans << endl;
    }
    return 0;
}