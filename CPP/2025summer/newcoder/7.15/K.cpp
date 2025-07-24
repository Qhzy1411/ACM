#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
set<pair<int, int>> hool;
void find(int nid, vector<vector<int>> &G, vector<int> &vis, vector<int> &hash, int n, vector<int> &firfloor) {
    if (vis[nid] == 1)
        return;
    int x = nid, y = G[nid][0];
    x = (x % n == 0) ? n : x % n;
    y = (y % n == 0) ? n : y % n;
    if (x > y)
        swap(x, y);
    hool.insert({x, y});
    hash[nid % n == 0 ? n : nid % n] = 1;
    vis[nid] = 1;
    if (nid <= n) {
        firfloor.push_back(nid);
    }
    find(G[nid][0], G, vis, hash, n, firfloor);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> G(3 * n + 1), F(n + 1);
        for (int i = 1; i <= n; i++) {
            int du;
            cin >> du;
            for (int j = 0; j < du; j++) {
                int v;
                cin >> v;
                F[i].push_back(v);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < F[i].size(); j++) {
                int k, m;
                for (int x = 0; x < F[F[i][j]].size(); x++) {
                    if (F[F[i][j]][x] == i) {
                        m = x;
                        break;
                    }
                }
                k = F[i][j];
                G[m * n + k].push_back((j + 1) % F[i].size() * n + i);
            }
        }
        vector<int> vis(3 * n + 1);
        int nid;

        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            nid = i;
            if (vis[nid] == 1)
                continue;
            hool.clear();
            vector<int> hash(n + 1), firfloor;
            find(nid, G, vis, hash, n, firfloor);
            int k = hool.size();
            for (int j = 0; j < firfloor.size(); j++) {
                ans[firfloor[j]] = k;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}