#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
const int INF = 1e18;
const double PI = 3.14159265358979;
int dp[301][301][301][3];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        int n, Q;
        cin >> n >> Q;
        string s;
        cin >> s;
        s = '*' + s + '*';
        int n_ = 0;
        vector<char> pre, after;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '?') {
                n_++;
                pre.emplace_back(s[i - 1]);
                after.emplace_back(s[i + 1]);
            }
        }
        dp[0][1][0][0] = 1;
        dp[0][0][1][1] = 1;
        dp[0][0][0][2] = 1;
        for (int i = 1; i < n_; i++) {

            for (int j = 1; j <= i + 1; j++) {
                for (int k = 1; k + j <= i + 1; k++) {
                    dp[i][j][k][0];
                    dp[i][j][k][1];
                    dp[i][j][k][2];
                    if (pre[i] == '?') {
                        if (j != 0 && after[i] != 'a') {
                            dp[i][j][k][0] = dp[i - 1][j - 1][k][1] + dp[i - 1][j - 1][k][2];
                        }
                        if (k != 0 && after[i] != 'b') {
                            dp[i][j][k][1] = dp[i - 1][j][k - 1][0] + dp[i - 1][j][k - 1][2];
                        }
                        if (j + k <= i && after[i] != 'c') {
                            dp[i][j][k][2] = dp[i - 1][j][k][0] + dp[i - 1][j][k][1];
                        }
                    } else {
                        if (pre[i] != 'a' && after[i] != 'a' && j != 0) {
                            dp[i][j][k][0] = dp[i - 1][j - 1][k][0] + dp[i - 1][j - 1][k][1] + dp[i - 1][j - 1][k][2];
                        }
                        if (pre[i] != 'b' && after[i] != 'b' && k != 0) {
                            dp[i][j][k][1] = dp[i - 1][j][k - 1][0] + dp[i - 1][j][k - 1][1] + dp[i - 1][j][k - 1][2];
                        }
                        if (pre[i] != 'c' && after[i] != 'c' && j + k <= i) {
                            dp[i][j][k][2] = dp[i - 1][j][k][0] + dp[i - 1][j][k][1] + dp[i - 1][j][k][2];
                        }
                    }
                }
            }
        }
        vector<vector<int>> sum(n_ + 2, vector<int>(n_ + 2));
        for (int j = 0; j < n_; j++) {
            for (int k = n_ - 1; k >= 0; k--) {
                if (k + j > n_)
                    continue;
                sum[j][k] = sum[j][k + 1] + dp[n_ - 1][j][k][0] + dp[n_ - 1][j][k][1] + dp[n_ - 1][j][k][2];
            }
        }
        while (Q--) {
            int x, y, z, ans = 0, lx, ly, lz;
            cin >> x >> y >> z;
            lx = min(n_, x);
            ly = min(n_, y);
            lz = min(n_, z);
            for (int i = 0; i < lx; i++) {
                if (ly > n_ - lz) {
                    ans += sum[i][n - lz - i] - sum[i][ly];
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}