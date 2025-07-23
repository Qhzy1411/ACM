// Author: QHZY
// Create_Time: 2025/07/23 09:16:34
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
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
inline int h(int x) { return x == 0 ? 0 : __lg(x) + 1; }
inline int gbit(int x, int k) { return ((x >> (k - 1)) & 1); }
void work() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c != 0) {
        cout << -1 << endl;
        return;
    }
    if (a == b && b == c) {
        cout << 0 << endl
             << endl;
        return;
    }
    vi op;
    if (h(a) > h(b)) {
        op.push_back(4);
        b ^= a;
    }
    if (h(a) < h(b)) {
        op.push_back(3);
        a ^= b;
    }
    if (h(a) > h(c)) {
        while (h(b) > h(c)) {
            if (h(b) == h(a)) {
                op.push_back(3);
                a ^= b;
            }
            op.push_back(2);
            b >>= 1;
        }
    }
    if (h(a) < h(b)) {
        op.push_back(3);
        a ^= b;
    }
    while (h(a) < h(c)) {
        if (gbit(c, h(c) - h(a) + h(b)) != gbit(a, h(b))) {
            op.push_back(3);
            a ^= b;
        }
        op.push_back(1);
        a <<= 1;
    }
    while (h(b) > 0) {
        if (gbit(c, h(b)) != gbit(a, h(b))) {
            op.push_back(3);
            a ^= b;
        }
        op.push_back(2);
        b >>= 1;
    }
    op.push_back(4);
    b ^= a;
    cout << op.size() << endl;
    for (int i : op)
        cout << i << ' ';
    cout << endl;
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