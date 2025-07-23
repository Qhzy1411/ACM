// Author: QHZY
// Create_Time: 2025/07/22 12:10:49
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using piii = pair<int, pii>;
#define pb push_back
#define fi first
#define se second
const ll INF = 0x3f3f3f3f3f3f3f3f;
void work() {
    int n, a, count0 = 1, count1 = 1, temp = 1, sum1 = 0, ans = 0;
    string s;
    cin >> n >> a;
    cin >> s;
    if (s[0] == '1')
        sum1++;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            temp++;
        } else if (s[i - 1] == '1') {
            count1 = max(count1, temp);
            temp = 1;
        } else {
            count0 = max(count0, temp);
            temp = 1;
        }
        if (s[i] == '1')
            sum1++;
    }
    if (s[n - 1] == '1')
        count1 = max(count1, temp);
    else
        count0 = max(count0, temp);
    if (count1 >= a) {
        ans = n;
    } else if (count0 >= a + 1) {
        ans = n;
    } else {
        ans = sum1;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        work();
    return 0;
}