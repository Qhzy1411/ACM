#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int root;
vector<int> num(2e5 + 5);
int dfs(vector<int> &max_h, vector<int> &fa, vector<pair<int, int>> &son, int now_h, int node) {
    num[now_h]++;
    int h = now_h;
    auto [ls, rs] = son[node];
    if (ls)
        h = max(h, dfs(max_h, fa, son, now_h + 1, ls));
    if (rs)
        h = max(h, dfs(max_h, fa, son, now_h + 1, rs));
    max_h[node] = h;
    return h;
}
int dfs2(vector<int> &max_h, int need_h, int node, vector<pair<int, int>> &son) {
    if (node == 0)
        return max(2 * need_h - 1, 0ll);
    int ans = 0;
    auto [ls, rs] = son[node];
    if (max_h[ls] > max_h[rs]) {
        ans += dfs2(max_h, need_h - 1, ls, son);
        ans += dfs2(max_h, need_h - 2, rs, son);
    } else {
        ans += dfs2(max_h, need_h - 1, rs, son);
        ans += dfs2(max_h, need_h - 2, ls, son);
    }
    return ans;
}
bool f(int mid, vector<int> &max_h, vector<pair<int, int>> &son) {
    if (dfs2(max_h, mid, root, son) + num[mid + 1] <= dfs2(max_h, mid + 1, root, son))
        return true;
    return false;
}
void work() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        num[i] = 0;
    vector<int> max_h(n + 1);
    vector<pair<int, int>> son(n + 1);
    vector<int> fa(n + 1);
    for (int i = 1; i <= n; i++) {
        int ls, rs;
        cin >> ls >> rs;
        fa[ls] = i;
        fa[rs] = i;
        son[i] = {ls, rs};
    }
    for (int i = 1; i <= n; i++)
        if (fa[i] == 0) {
            root = i;
            break;
        }
    dfs(max_h, fa, son, 1, root);
    int l = 1, r = max_h[1];
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (f(mid, max_h, son))
            r = mid - 1;
        else
            l = mid + 1;
    }
    int ans = dfs2(max_h, l, root, son);
    for (int i = l + 1; i <= n; i++)
        ans += num[i];
    cout << ans << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}