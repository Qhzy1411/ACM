#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
const int INF = 1e18;
const double PI = 3.14159265358979;
const int k = 2147483648;
bitset<k> num;
void f(int x, int y) {
    int a = 0, b = 0, c = 0;
    vector<int> xb, yb;
    while (x > 0) {
        xb.push_back(x % 2);
        x /= 2;
    }
    while (y > 0) {
        yb.push_back(y % 2);
        y /= 2;
    }
    for (int i = 0; i < min(yb.size(), xb.size()); i++) {
        if (xb[i] == 0 && yb[i] == 1) {
            b += 1 << i;
        } else if (xb[i] == 1 && yb[i] == 1) {
            c += 1 << i;
        } else if (xb[i] == 1 && yb[i] == 0) {
            a += 1 << i;
        }
    }
    if (yb.size() < xb.size()) {
        for (int i = yb.size(); i < xb.size(); i++) {
            if (xb[i] == 1) {
                a += 1 << i;
            }
        }
    } else {
        for (int i = xb.size(); i < yb.size(); i++) {
            if (yb[i] == 1) {
                b += 1 << i;
            }
        }
    }
    num.set(a), num.set(b), num.set(c);
    num.set(a + b), num.set(a + c), num.set(b + c);
    num.set(0), num.set(a + b + c);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;
        for (int i = 0; i < n - 1; i++) {
            f(a[i], a[i + 1]);
        }
        cout << num.count() << endl;
    }
    return 0;
}