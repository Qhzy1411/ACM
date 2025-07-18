// Author: QHZY
// Create_Time: 2025/07/17 12:22:05
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
#define int ll
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e6;
void work() {
    int x, y;
    cin >> x >> y;
    if (x == 1 || y == 1)
        cout << -1 << endl;
    else
        cout << 1 << endl;
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