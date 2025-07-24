#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
const int INF = 1e18;
const double PI = 3.14159265358979;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n, len;
        cin >> n;
        string s;
        cin >> s;
        vector<int> w(17);
        for (auto &x : w) {
            cin >> x;
        }
        cin >> len;
        if (len % 2 == 1)
            len++;
        vector<int> ok(1 << 17, 1);
        for (int i = 0; i + len - 1 < n; i++) {
            int f = 0;
            for (int x = 0; x < len / 2; x++) {
                int l = i + x, r = i + len - 1 - x;
                if (s[l] != s[r]) {
                    int mn = min(s[l] - 'a', s[r] - 'a');
                    f |= 1 << mn;
                } else {
                    f = 0;
                    break;
                }
            }
            if (f) {
                ok[f] = 0;
            }
        }
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < 1 << 17; j++) {
                if (j & 1 << i) {
                    ok[j] &= ok[j ^ (1 << i)];
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i < 1 << 17; i++) {
            if (ok[i] == 1) {
                int sum = 0;
                for (int j = 0; j < 17; j++) {
                    if (!(i & (1 << j))) {
                        sum += w[j];
                    }
                }
                ans = min(ans, sum);
            }
        }
        cout << ans << endl;
    }
    return 0;
}