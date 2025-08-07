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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        int cnt = 0, c0 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0) {
                cnt++;
            }
            if (a[i] == 0)
                c0++;
        }
        int ans = 0;
        if (cnt % 2 == 0) {
            ans = c0;
        } else {
            ans = 1 - a[cnt] + c0;
            if (c0 > 0) {
                ans = min(ans, c0);
            } else {
                if (cnt == n) {
                    ans = min(ans, 1 - a[n]);
                } else {
                    ans = min(ans, a[cnt + 1] + 1);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}