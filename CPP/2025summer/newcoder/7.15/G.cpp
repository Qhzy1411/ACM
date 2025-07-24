// Author: QHZY
// Create_Time: 2025/07/15 12:07:36
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e6;
int main() {
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    while (q--) {
        string str2;
        ll a;
        cin >> str2 >> a;
        a--;
        ll m = str2.length();
        vector<bool> match(m, false);
        for (int i = 0; i < m; i++) {
            if (str[a + i] == str2[i]) {
                match[i] = true;
            }
        }
        ll ans = 0;
        ll count = 0;
        for (int i = 0; i < m; i++) {
            if (match[i]) {
                count++;
            } else {
                ans += count * (count + 1) / 2;
                count = 0;
            }
        }
        ans += count * (count + 1) / 2;
        cout << ans << endl;
    }
    return 0;
}
