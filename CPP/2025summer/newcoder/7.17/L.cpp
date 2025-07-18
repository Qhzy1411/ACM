#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int MOD = 998244353;
int bfs(int node, vector<vector<int>> &g, vector<bool> &visited) {
    if (visited[node]) {
        return 0;
    }
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for (auto &i : g[u]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return count;
}
int qmi(int a, int b, int p) {
    int res = 1;
    while (b != 0) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int inv(int a, int p) {
    return qmi(a, p - 2, p);
}
void work() {
    int n;
    cin >> n;
    vector<bool> visited(n, false);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        g[i].push_back(a);
        g[a].push_back(i);
    }
    int count2 = 0;
    vector<int> odd_ring, even_ring;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int num = bfs(i, g, visited);
            if (num == 2)
                count2++;
            if (num & 1)
                odd_ring.push_back(num);
            else
                even_ring.push_back(num);
        }
    }
    if (odd_ring.size() != 0 && odd_ring.size() != 2) {
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    if (odd_ring.size() == 2) {
        for (auto &i : odd_ring) {
            ans *= i;
            ans %= MOD;
        }
        ans *= qmi(2, even_ring.size() - count2, MOD);
        ans %= MOD;
        cout << ans << endl;
    } else {
        int ans = 0;
        int num_e2 = even_ring.size() - count2;
        if (count2 > 0) {
            int t1 = count2;
            t1 = (t1 * qmi(2, num_e2, MOD)) % MOD;
            ans = (ans + t1) % MOD;
        }
        if (num_e2 > 0) {
            int t2s = 0;
            for (auto &i : even_ring) {
                if (i > 2) {
                    t2s = (t2s + i * i / 4) % MOD;
                }
            }
            int t2p = qmi(2, num_e2 - 1, MOD);
            int t2 = (t2s * t2p) % MOD;
            ans = (ans + t2) % MOD;
        }
        cout << ans << endl;
    }
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}