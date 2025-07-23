#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
vector<int> ans;
bool judge(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
void work() {
    int x, y;
    cin >> x >> y;
    int g = __gcd(x, y);
    int t = (x + y) / g;
    if (judge(t)) {
        int k = 0;
        while (t > 1) {
            t >>= 1;
            k++;
        }
        cout << k << endl;
    } else {
        cout << -1 << endl;
    }
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}