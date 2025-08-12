#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
struct status {
    int zhu;
    int len;
};
void work() {
    int n, w;
    cin >> n >> w;
    int l_index = 2, r_index = 1;
    bool l_repeated = true, r_repeated = true;
    vector<bool> now_equal(n + 10);
    vector<int> zhugan(n + 10); // 节点i到节点1的距离
    vector<int> max_len(n + 10);
    vector<int> index_x(n + 10);
    vector<status> g(n + 10);
    int last = 2, last_x = 2;
    zhugan[2] = w;
    index_x[1] = 1, index_x[2] = 2;
    g[1] = {1, 0}, g[2] = {2, 0};
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int w;
            cin >> w;
            last++;
            last_x++;
            zhugan[last] = zhugan[last - 1] + w;
            index_x[last_x] = last;
            g[last_x] = {last_x, 0};
            if (zhugan[last] > zhugan[l_index] + max_len[l_index]) {
                l_index = last;
                l_repeated = false;
            } else if (zhugan[last] == zhugan[l_index] + max_len[l_index]) {
                l_repeated = true;
            }
        }
        if (op == 2) {
            last_x++;
            int x, w;
            cin >> x >> w;
            g[last_x] = {g[x].zhu, g[x].len + w};
            if (g[x].len + w > max_len[g[x].zhu]) {
                max_len[index_x[g[x].zhu]] = g[x].len + w;
                now_equal[index_x[g[x].zhu]] = false;
                if (zhugan[index_x[g[x].zhu]] + max_len[index_x[g[x].zhu]] > zhugan[l_index] + max_len[l_index]) {
                    l_index = index_x[g[x].zhu];
                    l_repeated = false;
                } else if (zhugan[index_x[g[x].zhu]] + max_len[index_x[g[x].zhu]] == zhugan[l_index] + max_len[l_index]) {
                    l_repeated = true;
                    l_index = min(l_index, index_x[g[x].zhu]);
                }
                if (zhugan[last] - zhugan[index_x[g[x].zhu]] + max_len[index_x[g[x].zhu]] > zhugan[last] - zhugan[r_index] + max_len[r_index]) {
                    r_index = index_x[g[x].zhu];
                    r_repeated = false;
                } else if (zhugan[last] - zhugan[index_x[g[x].zhu]] + max_len[index_x[g[x].zhu]] == zhugan[last] - zhugan[r_index] + max_len[r_index]) {
                    r_repeated = true;
                    r_index = max(r_index, index_x[g[x].zhu]);
                }
            } else if (g[x].len + w == max_len[g[x].zhu])
                now_equal[index_x[g[x].zhu]] = true;
        }
        if (op == 3) {
            if (zhugan[l_index] + max_len[l_index] > zhugan[last] - zhugan[r_index] + max_len[r_index]) {
                int ans = zhugan[l_index];
                if (!l_repeated && !now_equal[l_index])
                    ans += max_len[l_index];
                cout << ans << endl;
            } else if (zhugan[l_index] + max_len[l_index] < zhugan[last] - zhugan[r_index] + max_len[r_index]) {
                int ans = zhugan[last] - zhugan[r_index];
                if (!r_repeated && !now_equal[r_index])
                    ans += max_len[r_index];
                cout << ans << endl;
            } else {
                int ans = max(0ll, zhugan[l_index] - zhugan[r_index]);
                cout << ans << endl;
            }
        }
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