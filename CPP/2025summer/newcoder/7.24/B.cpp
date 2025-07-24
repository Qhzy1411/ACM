#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int n, m, k;
int now_index, fast_index;
void dfs1(vector<string> &g, pair<int, int> &point, vector<vector<bool>> &visited) {
    auto [x, y] = point;
    visited[x][y] = true;
    if (x > 0 && !visited[x - 1][y] && g[x - 1][y] != '1') {
        pair<int, int> t = {x - 1, y};
        dfs1(g, t, visited);
    }
    if (x < n - 1 && !visited[x + 1][y] && g[x + 1][y] != '1') {
        pair<int, int> t = {x + 1, y};
        dfs1(g, t, visited);
    }
    if (y > 0 && !visited[x][y - 1] && g[x][y - 1] != '1') {
        pair<int, int> t = {x, y - 1};
        dfs1(g, t, visited);
    }
}
void dfs2(vector<string> &g, pair<int, int> &point, vector<vector<bool>> &visited) {
    auto [x, y] = point;
    visited[x][y] = true;
    if (x > 0 && !visited[x - 1][y] && g[x - 1][y] != '1') {
        pair<int, int> t = {x - 1, y};
        dfs2(g, t, visited);
    }
    if (x < n - 1 && !visited[x + 1][y] && g[x + 1][y] != '1') {
        pair<int, int> t = {x + 1, y};
        dfs2(g, t, visited);
    }
    if (y < m - 1 && !visited[x][y + 1] && g[x][y + 1] != '1') {
        pair<int, int> t = {x, y + 1};
        dfs2(g, t, visited);
    }
    fast_index = max(fast_index, y);
}
void work() {
    cin >> n >> m >> k;
    vector<string> g(n);
    vector<vector<bool>> visited(n, vector<bool>(m)), visited2(n, vector<bool>(m));
    for (auto &i : g)
        cin >> i;
    pair<int, int> t = {0, m - 1};
    dfs1(g, t, visited);
    pair<int, int> t1 = {0, 0};
    dfs2(g, t1, visited2);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (!visited[i][j] && g[i][j] != '1' && visited2[i][j]) {
                now_index = j, fast_index = j;
                pair<int, int> t = {i, j};
                dfs2(g, t, visited);
                if (fast_index - now_index + 1 >= k) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}