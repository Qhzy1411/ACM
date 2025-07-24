#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
const int INF = 1e18;
const double PI = 3.14159265358979;
int n, m;
void dfs1(pair<int, int> p, vector<vector<int>> &vis, int &nbox, int &ntar, vector<vector<char>> &G) {
    pair<int, int> ne;
    if (p.first > 1 && G[p.first - 1][p.second] != '#' && vis[p.first - 1][p.second] == 0) {
        ne = {p.first - 1, p.second};
        vis[ne.first][ne.second] = 1;
        if (G[p.first - 1][p.second] == '@')
            nbox++;
        if (G[p.first - 1][p.second] == '*')
            ntar++;
        dfs1(ne, vis, nbox, ntar, G);
    }
    if (p.first < n && G[p.first + 1][p.second] != '#' && vis[p.first + 1][p.second] == 0) {
        ne = {p.first + 1, p.second};
        vis[ne.first][ne.second] = 1;
        if (G[p.first + 1][p.second] == '@')
            nbox++;
        if (G[p.first + 1][p.second] == '*')
            ntar++;
        dfs1(ne, vis, nbox, ntar, G);
    }
    if (p.second > 1 && G[p.first][p.second - 1] != '#' && vis[p.first][p.second - 1] == 0) {
        ne = {p.first, p.second - 1};
        vis[ne.first][ne.second] = 1;
        if (G[p.first][p.second - 1] == '@')
            nbox++;
        if (G[p.first][p.second - 1] == '*')
            ntar++;
        dfs1(ne, vis, nbox, ntar, G);
    }
    if (p.second < m && G[p.first][p.second + 1] != '#' && vis[p.first][p.second + 1] == 0) {
        ne = {p.first, p.second + 1};
        vis[ne.first][ne.second] = 1;
        if (G[p.first][p.second + 1] == '@')
            nbox++;
        if (G[p.first][p.second + 1] == '*')
            ntar++;
        dfs1(ne, vis, nbox, ntar, G);
    }
}
void dfs2(pair<int, int> p, vector<vector<int>> &vis, vector<vector<char>> &G, int &f, vector<pair<int, int>> &road) {
    pair<int, int> ne;
    if (G[p.first][p.second] == '*') {
        f = 1;
        road.push_back(p);
        return;
    }
    if (p.first > 1 && G[p.first - 1][p.second] != '#' && vis[p.first - 1][p.second] == 0) {
        ne = {p.first - 1, p.second};
        vis[ne.first][ne.second] = 1;
        dfs2(ne, vis, G, f, road);
        if (f) {
            road.push_back(p);
            return;
        }
    }
    if (p.first < n && G[p.first + 1][p.second] != '#' && vis[p.first + 1][p.second] == 0) {
        ne = {p.first + 1, p.second};
        vis[ne.first][ne.second] = 1;
        dfs2(ne, vis, G, f, road);
        if (f) {
            road.push_back(p);
            return;
        }
    }
    if (p.second > 1 && G[p.first][p.second - 1] != '#' && vis[p.first][p.second - 1] == 0) {
        ne = {p.first, p.second - 1};
        vis[ne.first][ne.second] = 1;
        dfs2(ne, vis, G, f, road);
        if (f) {
            road.push_back(p);
            return;
        }
    }
    if (p.second < m && G[p.first][p.second + 1] != '#' && vis[p.first][p.second + 1] == 0) {
        ne = {p.first, p.second + 1};
        vis[ne.first][ne.second] = 1;
        dfs2(ne, vis, G, f, road);
        if (f) {
            road.push_back(p);
            return;
        }
    }
}
struct DO {
    int x, y;
    char d;
};
int find(vector<pair<int, int>> &road, int u, vector<vector<char>> &G) {
    for (int i = u - 1; i >= 0; i--) {
        pair<int, int> ne = road[i];
        if (G[ne.first][ne.second] != '@' && G[ne.first][ne.second] != '!') {
            return i;
        }
    }
    return 0;
}
void swapG(pair<int, int> a, pair<int, int> b, vector<vector<char>> &G, vector<DO> &ans) {
    char d;
    if (b.first == a.first + 1)
        d = 'D';
    else if (b.first == a.first - 1)
        d = 'U';
    else if (b.second == a.second + 1)
        d = 'R';
    else
        d = 'L';
    if (G[a.first][a.second] == '@') {
        if (G[b.first][b.second] == '.') {
            swap(G[a.first][a.second], G[b.first][b.second]);
        } else if (G[b.first][b.second] == '*') {
            G[a.first][a.second] = '.';
            G[b.first][b.second] = '!';
        }
    } else if (G[a.first][a.second] == '!') {
        if (G[b.first][b.second] == '.') {
            G[a.first][a.second] = '*';
            G[b.first][b.second] = '@';
        } else if (G[b.first][b.second] == '*') {
            swap(G[a.first][a.second], G[b.first][b.second]);
        }
    }
    ans.push_back({a.first, a.second, d});
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        cin >> n >> m;
        vector<vector<char>> G(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> G[i][j];
            }
        }
        vector<vector<int>> vis1(n + 1, vector<int>(m + 1));
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (vis1[i][j] == 0 && G[i][j] != '#') {
                    pair<int, int> p = {i, j};
                    int nbox = 0, ntar = 0;
                    if (G[i][j] == '@')
                        nbox++;
                    if (G[i][j] == '*')
                        ntar++;
                    vis1[i][j] = 1;
                    dfs1(p, vis1, nbox, ntar, G);
                    if (nbox != ntar) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (!flag) {
            cout << -1 << endl;
            continue;
        }
        vector<DO> ans;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (G[i][j] == '@') {
                    vector<pair<int, int>> road;
                    int f = 0;
                    pair<int, int> p = {i, j};
                    vector<vector<int>> vis2(n + 1, vector<int>(m + 1));
                    vis2[i][j] = 1;
                    dfs2(p, vis2, G, f, road);
                    for (int k = road.size() - 1; k >= 1; k--) {
                        pair<int, int> ne = road[k - 1], now = road[k];
                        char d;
                        if (ne.first == now.first + 1)
                            d = 'D';
                        else if (ne.first == now.first - 1)
                            d = 'U';
                        else if (ne.second == now.second + 1)
                            d = 'R';
                        else
                            d = 'L';
                        if (G[ne.first][ne.second] == '.') {
                            ans.push_back({now.first, now.second, d});
                            G[ne.first][ne.second] = '@';
                            if (G[now.first][now.second] == '@') {
                                G[now.first][now.second] = '.';
                            } else if (G[now.first][now.second] == '!') {
                                G[now.first][now.second] = '*';
                            }
                        } else if (G[ne.first][ne.second] == '@' || G[ne.first][ne.second] == '!') {
                            int end = find(road, k, G);
                            pair<int, int> a = road[k], b = road[end];
                            for (int tt = end + 1; tt <= k; tt++) {
                                swapG(road[tt], road[tt - 1], G, ans);
                            }
                            // if(G[b.first][b.second]=='.') G[b.first][b.second]='@';
                            // else G[b.first][b.second]='!';
                            // G[a.first][a.second]='.';
                            k = end + 1;
                        } else {
                            swapG(now, ne, G, ans);
                            break;
                        }
                    }
                }
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].x << ' ' << ans[i].y << ' ' << ans[i].d << endl;
        }
    }
    return 0;
}