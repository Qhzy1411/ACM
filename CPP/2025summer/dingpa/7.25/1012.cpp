#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
const int INF = 1e18;
const double PI = 3.14159265358979;
int mod = 1e9 + 7;
struct NODE {
    int x, y;
    int a;
    double com_x, com_y;
};
bool com1(NODE a, NODE b) {
    return a.com_x < b.com_x;
}
bool com2(NODE a, NODE b) {
    return a.com_y < b.com_y;
}
long long power(long long a, long long b) {
    a %= mod;
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
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
        vector<NODE> node(n);
        for (int i = 0; i < n; i++) {
            cin >> node[i].x >> node[i].y >> node[i].a;
            node[i].com_x = (node[i].x + node[i].y) / 2.0;
            node[i].com_y = (node[i].x - node[i].y) / 2.0;
            node[i].x += mod, node[i].y += mod;
            node[i].x %= mod, node[i].y %= mod;
            int temp1 = (node[i].x + node[i].y) * power(2, mod - 2) % mod;
            int temp2 = (node[i].x - node[i].y + mod) * power(2, mod - 2) % mod;
            node[i].x = temp1, node[i].y = temp2;
        }
        sort(node.begin(), node.end(), com1);
        vector<int> sum(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            sum[i] = sum[i + 1] + node[i].a;
            sum[i] %= mod;
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += (node[i + 1].x - node[i].x + mod) % mod * (((n - i - 1) * (sum[0] - sum[i + 1] + mod) % mod + (i + 1) * sum[i + 1]) % mod) % mod;
            ans %= mod;
        }
        sort(node.begin(), node.end(), com2);
        for (int i = n - 1; i >= 0; i--) {
            sum[i] = sum[i + 1] + node[i].a;
            sum[i] %= mod;
        }
        for (int i = 0; i < n - 1; i++) {
            ans += (node[i + 1].y - node[i].y + mod) % mod * (((n - i - 1) * (sum[0] - sum[i + 1] + mod) % mod + (i + 1) * sum[i + 1]) % mod) % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}