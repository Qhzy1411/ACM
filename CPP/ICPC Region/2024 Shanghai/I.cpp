#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int mod = 998244353;
void work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    int now = a[0] % mod, i = 1;
    while (i + k - 2 < n) {
        bool f = false;
        for (int j = 0; j < k - 1; j++) {
            if (a[i + j] == 0)
                f = true;
        }
        if (f)
            break;
        for (int j = 0; j < k - 1; j++) {
            now *= a[i];
            now %= mod;
            i++;
        }
    }
    cout << now << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}