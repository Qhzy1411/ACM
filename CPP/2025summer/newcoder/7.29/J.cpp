#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int n, m;
const ll INF = 0x3f3f3f3f3f3f3f3f;
void bfs(vector<vector<bool>> &visited, vector<vector<int>> &g, queue<pair<int, int>> &q) {
    int t = q.size();
    while (t--) {
        auto [i, j] = q.front();
        q.pop();
        if (i > 0 && g[i - 1][j] == 0 && !visited[i - 1][j]) {
            q.push({i - 1, j});
            visited[i - 1][j] = true;
        }
        if (j < m - 1 && g[i][j + 1] == 0 && !visited[i][j + 1]) {
            q.push({i, j + 1});
            visited[i][j + 1] = true;
        }
        if (i < n - 1 && g[i + 1][j] == 0 && !visited[i + 1][j]) {
            q.push({i + 1, j});
            visited[i + 1][j] = true;
        }
        if (j > 0 && g[i][j - 1] == 0 && !visited[i][j - 1]) {
            q.push({i, j - 1});
            visited[i][j - 1] = true;
        }
    }
}
bool pd(int mid, vector<vector<int>> &g) {
    int temp = mid;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }
    while (mid--)
        bfs(visited, g, q);
    int max_x = -INF, min_x = INF;
    int max_y = -INF, min_y = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j]) {
                int x = i, y = j;
                max_x = max(x + y, max_x);
                min_x = min(x + y, min_x);
                max_y = max(x - y, max_y);
                min_y = min(x - y, min_y);
            }
    if (max_x < min_x)
        return true;
    int dis2 = max((max_x - min_x + 1) / 2, (max_y - min_y + 1) / 2);
    if ((max_x - min_x) % 2 == 0 && (max_y - min_y) % 2 == 0 && (max_x - min_x + 1) / 2 == (max_y - min_y + 1) / 2) {
        int new_x = (max_x + min_x) / 2, new_y = (max_y + min_y) / 2;
        if (new_x % 2 + new_y % 2 == 1)
            dis2++;
    }
    if (dis2 <= temp)
        return true;
    return false;
}
void work() {
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (auto &i : g)
        for (auto &j : i)
            cin >> j;
    int l = 0, r = n * m;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (pd(mid, g))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    // int _;cin>>_;while(_--)
    work();
    return 0;
}