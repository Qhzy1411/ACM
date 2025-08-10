#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
const int INF = 1e18;
const double PI = 3.14159265358979;
int n, x;
int num, np[10000001] = {1};
void dfs(int u, int fa, vector<vector<int>> &tr, vector<int> &a, vector<vector<int>> &f, int &ans) {
    if (a[u] != -1) {
        f[u][a[u]] = 1;
    }
    for (int vi = 0; vi < tr[u].size(); vi++) {
        int v = tr[u][vi];
        if (v == fa)
            continue;
        dfs(v, u, tr, a, f, ans);
        if (a[v] == -1)
            continue;
    }
    for (int vi = 0; vi < tr[u].size(); vi++) {
        int v = tr[u][vi];
        if (v == fa)
            continue;
        if (a[u] == -1)
            return;
        vector<int> s = f[u];
        for (int j = 0; j < num; j++) {
            for (int i = 0; i < (1 << num); i++) {
                if (!(i >> j & 1)) {
                    s[i] += s[(1 << j) ^ i];
                }
            }
        }
        for (int i = 0; i < (1 << num); i++) {
            int x = a[u] | i;
            ans += f[v][i] * s[((1 << num) - 1) ^ x];
            f[u][x] += f[v][i];
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    int N = 1e7;
    vector<int> primes;
    np[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!np[i]) {
            primes.push_back(i);
            for (int k = i * 2; k <= N; k += i) {
                np[k] = 1;
            }
        }
    }
    while (T--) {
        // cout<<'*'<<endl;
        cin >> n >> x;
        vector<vector<int>> tr(n + 1);
        vector<int> a(n + 1), b(n + 1), yz;
        map<int, int> yznum;
        int temp = x, k = 0;
        num = 0;
        while (temp > 1) {
            int flag = 1;
            while (temp % primes[k] == 0) {
                yznum[primes[k]]++;
                temp /= primes[k];
                if (flag) {
                    yz.push_back(primes[k]);
                    num++;
                    flag = 0;
                }
            }
            k++;
        }
        // cout<<yz.size()<<endl;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == x)
                ans++;
            int bit_of_a = 0, t = 0;
            temp = a[i];
            while (temp > 1) {
                if (t == yz.size()) {
                    bit_of_a = -1;
                    break;
                }
                int countyz = 0;
                while (temp % yz[t] == 0) {
                    temp /= yz[t];
                    countyz++;
                }
                if (countyz == yznum[yz[t]]) {
                    bit_of_a += ((1ll) << t);
                } else if (countyz > yznum[yz[t]]) {
                    bit_of_a = -1;
                    break;
                }
                // cout<<a[i]<<' '<<yz[t]<<' '<<t<<endl;
                t++;
            }
            b[i] = bit_of_a;
        }
        // cout<<'&'<<endl;
        vector<vector<int>> f(n + 1, vector<int>(1 << (num + 1)));
        dfs(1, 0, tr, b, f, ans);
        cout << ans << endl;
    }
    return 0;
}