// Author: QHZY
// Create_Time: 2025/07/21 12:02:59
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld
using pii = pair<int, int>;
using piii = pair<int, pii>;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll N = 1e6;
void work() {
    int n, x, y;
    cin >> n >> x >> y;
    int countx = 0, county = 0;
    int lowx = 0, lowy = 0;
    bool flag = true;
    while (x > 0) {
        if (x & 1) {
            flag = false;
            countx++;
        }
        if (flag)
            lowx++;
        x /= 2;
    }
    flag = true;
    while (y > 0) {
        if (y & 1) {
            flag = false;
            county++;
        }
        if (flag)
            lowy++;
        y /= 2;
    }
    if (countx == county || lowx == lowy) {
        cout << 1 << endl;
        return;
    } else {
        cout << 2 << endl;
    }
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