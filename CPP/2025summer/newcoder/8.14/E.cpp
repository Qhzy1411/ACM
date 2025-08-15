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
		vector<vector<vector<vector<pair<int, int>>>>> dp(n + 1, vector<vector<vector<pair<int, int>>>>(201, vector<vector<pair<int, int>>>(201, vector<pair<int, int>>(2))));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 200; j++) {
				for (int k = j; k <= 200; k++) {
					if (j < a[i] && k < a[i]) {
						dp[i][j][k][0].first = INF;
						dp[i][j][k][0].second = INF;
						dp[i][j][k][1].first = INF;
						dp[i][j][k][1].second = INF;
					} else if (j < a[i] && k >= a[i]) {
						dp[i][j][k][0].first = INF;
						dp[i][j][k][0].second = INF;
						dp[i][j][k][1].second = k - a[i];
						dp[i][j][k][1].first = min(dp[i - 1][j][k][0].first + max(0LL, dp[i][j][k][1].second - dp[i - 1][j][k][0].second), dp[i - 1][j][k][1].first + max(0LL, dp[i][j][k][1].second - dp[i - 1][j][k][1].second));
					} else {
						int temp1 = j - a[i], temp2 = maxai - a[i];
						dp[i][j][k][0].first = min(max(temp1 - dp[i - 1][j][k][0].second, 0LL) + dp[i - 1][j][k][0].first, max(temp1 - dp[i - 1][j][k][1].second, 0LL) + dp[i - 1][j][k][1].first);
						dp[i][j][k][0].second = temp1;
						dp[i][j][k][1].first = min(max(temp2 - dp[i - 1][j][k][0].second, 0LL) + dp[i - 1][j][k][0].first, max(temp2 - dp[i - 1][j][k][1].second, 0LL) + dp[i - 1][j][k][1].first);
						dp[i][j][k][1].second = temp2;
					}
				}
			}
		}
		int ans = 1e9;
		if (m == 2) {
			for (int x = 0; x <= 200; x++) {
				for (int y = x; y <= 200; y++) {
					int k = 0;
					k = min(dp[n][x][y][0].first, dp[n][x][y][1].first);
					ans = min(ans, k);
				}
			}
		} else {
			for(int x=0;x<=200;x++){
				ans=min(ans,dp[n][x][x][1].first);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
1
6 2
16 89 28 8 96 17
*/