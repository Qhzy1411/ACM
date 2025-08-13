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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), ans(n);
        map<int, int> id;
        queue<int> q;
        int max1 = 0, max2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            id[a[i]] = i;
            q.push(a[i]);
            if (a[i] > max1) {
                max2 = max1;
                max1 = a[i];
            } else if (a[i] > max2) {
                max2 = a[i];
            }
        }
        q.pop();
        int now = a[0], cnt = 0, cu, count = 0;
        vector<int> xl;
        while (count < k) {
            count++;
            cu = q.front();
            q.pop();
            ans[id[now]]++;
            ans[id[cu]]++;
            if (now == max2 && cu == max1) {
                xl.push_back(max1);
                while (!q.empty()) {
                    xl.push_back(q.front());
                    q.pop();
                }
                xl.push_back(max2);
                break;
            }
            if (cnt == n - 1) {
                cnt = 1;
                q.push(now);
                now = cu;
                continue;
            }
            if (now > cu) {
                cnt++;
                q.push(cu);
            } else {
                cnt = 1;
                q.push(now);
                now = cu;
            }
        }
        int round = (k - count) / (2 * n - 2);
        int sy = (k - count) % (2 * n - 2);
        for (int i = 0; i < (int)xl.size(); i++) {
            q.push(xl[i]);
        }
        now = q.front();
        q.pop();
        cnt = 1;
        while (sy--) {
            cu = q.front();
            q.pop();
            ans[id[now]]++;
            ans[id[cu]]++;
            if (cnt == n - 1) {
                q.push(cu);
                now = cu;
                cnt = 1;
                continue;
            }
            if (now > cu) {
                cnt++;
                q.push(cu);
            } else {
                q.push(now);
                now = cu;
                cnt = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == max1 || a[i] == max2) {
                cout << ans[i] + round * n << ' ';
            } else {
                cout << ans[i] + 2 * round << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}