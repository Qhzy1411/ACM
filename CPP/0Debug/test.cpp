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
        string s;
        cin >> n >> s;
        s = '0' + s;
        int q0 = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                q0 = 0;
                break;
            }
        }
        if (q0) {
            cout << "Yes" << endl;
            continue;
        }
        if (n >= 1 && s[n - 1] == '0' && s[n] == '0') {
            cout << "Yes" << endl;
            continue;
        }
        if (n < 5) {
            if (n < 4) {
                int f = 1;
                for (int i = 1; i <= n; i++) {
                    if (s[i] == '1') {
                        f = 0;
                        break;
                    }
                }
                if (f) {
                    cout << "Yes" << endl;
                } else {
                    if (n == 1 || n == 2) {
                        cout << "No" << endl;
                    } else {
                        if (s[2] == '1' || s[3] == '1') {
                            cout << "No" << endl;
                        } else {
                            cout << "Yes" << endl;
                        }
                    }
                }
                continue;
            }
            if (s[n] == '0' && s[n - 1] == '0') {
                cout << "Yes" << endl;
            } else {
                if (s[n - 3] == '0' || (s[n - 3] == '1' && s[n - 2] == '0' && s[n - 1] == '0')) {
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
            }
            continue;
        }
        vector<int> cnt, st;
        int sz = 0, sta, endd;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1' && s[i - 1] == '0') {
                sz++;
                st.push_back(i);
                cnt.push_back(1);
            } else if (s[i] == '1' && s[i - 1] == '1') {
                cnt[sz - 1]++;
            }
        }
        sta = st[0];
        for (int i = 0; i < sz - 1; i++) {
            int en = st[i] + 2 * (cnt[i] - 1);
            // cout<<"st:"<<st[i]<<' '<<"cnt:"<<cnt[i]<<' '<<"en:"<<en<<endl;
            if (en >= st[i + 1] - 1) {
                int d = en - st[i + 1] + 1;
                cnt[i + 1] += d + 1;
                st[i + 1] -= d + 1;
            } else {
                if (en < st[i + 1] - 2)
                    sta = st[i + 1];
            }
        }
        for (int i = n; i >= 0; i--) {
            if (s[i] == '1') {
                endd = i;
                break;
            }
        }
        // cout<<"st:"<<st[sz-1]<<' '<<"cnt:"<<cnt[sz-1]<<' '<<"en:"<<en<<endl;
        // cout<<en<<' '<<tar<<endl;
        if (endd <= n - 2 || (endd > n - 2 && sta <= n - 3)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}