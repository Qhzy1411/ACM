#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N = 1e4 + 10; // 最大点数
vector<int> adj[N];     // 邻接表
int dfn[N], low[N], timestamp;
bool inStack[N];
stack<int> stk;

int scc_id[N], scc_cnt; // 每个点所属的强连通分量编号，总SCC数
vector<vector<int>> sccs;

vector<int> aa(N);
vector<int> belong(N);
vector<vector<int>> g(N);
vector<int> visited(N);
// Tarjan核心算法
void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        vector<int> scc;
        int v;
        do {
            v = stk.top();
            stk.pop();
            inStack[v] = false;
            scc_id[v] = scc_cnt;
            scc.push_back(v);
        } while (v != u);
        sccs.push_back(scc);
        scc_cnt++;
    }
}
set<int> design;
// 外部调用接口
void find_scc(int n) {
    timestamp = scc_cnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(inStack, 0, sizeof(inStack));
    while (!stk.empty())
        stk.pop();
    sccs.clear();

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}
int dfs(int node) {
    int quan = aa[node];
    for (auto next : g[node]) {
        if (visited[next] == -1) {
            quan += dfs(next);
        } else
            quan += visited[next];
    }
    visited[node] = quan;
    design.insert(quan);
    return quan;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        visited[i] = -1;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<bool> not_root(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        not_root[v] = true;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    find_scc(n);
    int root;
    for (int i = 1; i <= n; i++) {
        if (!not_root[i]) {
            root = i;
            break;
        }
    }
    for (int i = 0; i < scc_cnt; i++) {
        for (int j = 0; j < sccs[i].size(); j++) {
            aa[i] += a[sccs[i][j]];
            belong[sccs[i][j]] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : adj[i]) {
            if (belong[i] != belong[j])
                g[belong[i]].push_back(belong[j]);
        }
    }
    root = belong[root];
    dfs(root);
    cout << design.size() + 1 << endl;
    return 0;
}