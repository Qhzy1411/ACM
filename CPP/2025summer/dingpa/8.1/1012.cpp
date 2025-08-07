#include <bits/stdc++.h>
using namespace std;
#include <random>
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
const int INF = 1e18;
const double PI = 3.14159265358979;
mt19937 rng(random_device{}());
uniform_int_distribution<int> suiji(1, INF);
bool com(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<pair<int, int>> d1(n), d2(n);
        for (int i = 0; i < n; i++) {
            d1[i].first = (a[i] - b[i]);
            d2[i].first = (a[i] + b[i]);
            d1[i].second = i;
            d2[i].second = i;
        }
        sort(d1.begin(), d1.end(), com);
        sort(d2.begin(), d2.end(), com);
        int ans = 1e18;
        for (int i = 1; i < n; i++) {
            if (ans > d1[i].first - d1[i - 1].first) {
                ans = d1[i].first - d1[i - 1].first;
            }
            if (ans > d2[i].first - d2[i - 1].first) {
                ans = d2[i].first - d2[i - 1].first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}