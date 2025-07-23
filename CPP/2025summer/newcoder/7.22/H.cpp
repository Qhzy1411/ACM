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
const ll N = 1e6 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
vvi edge(N);
vi dep(N); // u,l,r
int fa[N][31];
void dfs(int root, int fno) {
    fa[root][0] = fno;
    dep[root] = dep[fa[root][0]] + 1;
    for (int i = 1; i < 31; ++i) {
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
    }
    int sz = edge[root].size();
    for (int i = 0; i < sz; ++i) {
        if (edge[root][i] == fno)
            continue;
        dfs(edge[root][i], root);
    }
}
void work() {
    int n, k;
    cin >> n >> k;
    int temp;
    vector<piii> jiedian(k);
    for (int i = 2; i <= n; i++) {
        cin >> temp;
        edge[temp].pb(i);
        edge[i].pb(temp);
    }
    for (int i = 0; i < k; i++) {
        cin >> jiedian[i].fi >> jiedian[i].se.fi >> jiedian[i].se.se;
    }
    dfs(1, 0);
    vector<bool> access(N);
    access[1] = true;
    for (auto [u, lr] : jiedian) {
        auto l = lr.fi, r = lr.se;
        int v = u, uu = u;
        if (u == 1) {
            cout << l << endl;
            return;
        }
        for (int i = 20; i >= 0; i--) {
            if (fa[v][i] && !access[fa[v][i]]) {
                v = fa[v][i];
            }
        }
        int down_dep = dep[v] - l + r;
        if (down_dep < dep[u]) {
            for (int i = 20; i >= 0; i--) {
                if (fa[u][i] && dep[fa[u][i]] > down_dep)
                    u = fa[u][i];
            }
            u--;
        }
        while (1) {
            // times[u] = l + dep[u] - dep[v];
            access[u] = true;
            if (u == v)
                break;
            u = fa[u][0];
        }
        if (access[uu]) {
            cout << l + dep[uu] - dep[v] << endl;
            return;
        }
    }
    cout << -1 << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        work();
    return 0;
}