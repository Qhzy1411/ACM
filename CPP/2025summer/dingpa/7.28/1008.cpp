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
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int flag = (x - z) * 1.0 / (x - y);
        flag++;
        list<int> lia;
        vector<int> a(n + 1);
        vector<int> num(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            num[a[i]]++;
        }
        sort(a.begin() + 1, a.end());
        int len = 0, ans = 0, sumx = 1, sumy = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != a[i - 1])
                lia.push_back(a[i]);
        }
        for (auto it = lia.begin(); lia.size();) {
            if (num[*it]) {
                len++;
                num[*it]--;
                if (num[*it] == 0) {
                    auto now = it;
                    it++;
                    if (it == lia.end()) {
                        if (len >= flag)
                            sumx += len - 1;
                        else
                            sumy += len;
                        len = 0;
                        it = lia.begin();
                    } else {
                        if (lia.size() == 2) {
                            len++;
                            num[*lia.rbegin()]--;
                            if (len >= flag)
                                sumx += len - 1;
                            else
                                sumy += len;
                        }
                    }
                    lia.erase(now);
                    if (lia.size() == 1)
                        break;
                } else {
                    it++;
                    if (it == lia.end()) {
                        if (len >= flag)
                            sumx += len - 1;
                        else
                            sumy += len;
                        len = 0;
                        it = lia.begin();
                        continue;
                    }
                }
            }
        }
        sumy += num[*lia.begin()];
        if (sumx + sumy > n) /********************************************************************/
            sumy--;
        ans = sumx * x + sumy * y + z * (n - sumx - sumy);
        int ans1 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[i - 1])
                ans1 += x;
            else if (a[i] < a[i - 1])
                ans1 += z;
            else
                ans1 += y;
        }
        ans = max(ans, ans1);
        cout << ans << endl;
    }
    return 0;
}