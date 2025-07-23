// Author: QHZY
// Create_Time: 2025/07/18 14:52:27
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld
using pii = pair<int, int>;
using piii = pair<int, pii>;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll N = 1e6;
void work() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    vector<unordered_map<int, int>> dist(n + 1);
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({0, {1, -1}});
    int answer = INT_MAX;
    while (!pq.empty()) {
        auto [cost, temp] = pq.top();
        auto [u, cp] = temp;
        pq.pop();
        if (u == n) {
            answer = cost;
            break;
        }
        if (dist[u].count(cp) && dist[u][cp] < cost) {
            continue;
        }
        for (auto [v, c] : adj[u]) {
            int newcost = cost + (c == cp ? 0 : 1);
            if (!dist[v].count(c) || newcost < dist[v][c]) {
                dist[v][c] = newcost;
                pq.push({newcost, {v, c}});
            }
        }
    }
    cout << answer << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        work();
    return 0;
}