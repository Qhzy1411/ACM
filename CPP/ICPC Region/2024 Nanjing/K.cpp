#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int red_loc;
int n, m, k, w;
vector<int> rl;
vector<int> process(int bl, int br, vector<int> &a) {
    vector<int> now_rl;
    int need_l = bl + 1;
    while (red_loc < (ll)a.size() && a[red_loc] < br) {
        if (a[red_loc] >= need_l) {
            now_rl.push_back(a[red_loc]);
            need_l = a[red_loc] + k;
        }
        red_loc++;
    }
    for (int i = now_rl.size() - 1; i >= 0; i--) {
        int now_com;
        if (i == (ll)now_rl.size() - 1)
            now_com = br;
        else
            now_com = now_rl[i + 1];
        int back = now_rl[i] + k - now_com;
        if (back > 0)
            now_rl[i] -= back;
    }
    return now_rl;
}
void work() {
    red_loc = 0;
    cin >> n >> m >> k >> w;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    b.push_back(0);
    b.push_back(w + 1);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<int, int>> areas;
    for (int i = 0; i < (ll)b.size() - 1; i++)
        areas.push_back({b[i], b[i + 1]});
    vector<int> ans;
    for (auto [bl, br] : areas) {
        vector<int> now_rl = process(bl, br, a);
        if (now_rl.size() && now_rl[0] <= bl) {
            cout << -1 << endl;
            return;
        }
        for (auto i : now_rl)
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}