// Author: QHZY
// Create_Time: 2025/07/17 12:54:20
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
#define int ll
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e6;
void work() {
    int n, t, ans = 0, maxc = 0, count = 0;
    cin >> n >> t;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        s[i] = temp - '0';
    }
    vector<vector<int>> fire(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        if (s[i] == 1)
            fire[i][0] = 0;
        else
            fire[i][0] = fire[i == 0 ? n - 1 : i - 1][0] + 1;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 1)
            fire[i][0] = 0;
        else
            fire[i][0] = fire[i == 0 ? n - 1 : i - 1][0] + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 1)
            fire[i][1] = 0;
        else
            fire[i][1] = fire[i == n - 1 ? 0 : i + 1][1] + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 1)
            fire[i][1] = 0;
        else
            fire[i][1] = fire[i == n - 1 ? 0 : i + 1][1] + 1;
    }
    for (int i = 0; i < n; i++) {
        if (fire[i][0] > t && fire[i][1] > t)
            ans++;
        if ((fire[i][0] > t && fire[i][1] <= t && fire[i][1] > 1) || (fire[i][1] > t && fire[i][0] <= t && fire[i][0] > 1))
            count++;
        else {
            maxc = max(maxc, count);
            maxc = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((fire[i][0] > t && fire[i][1] <= t && fire[i][1] > 1) || (fire[i][1] > t && fire[i][0] <= t && fire[i][0] > 1))
            count++;
        else {
            maxc = max(maxc, count);
            count = 0;
        }
    }
    cout << ans + maxc << endl;
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