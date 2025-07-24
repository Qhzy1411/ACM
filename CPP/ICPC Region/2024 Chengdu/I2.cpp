#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
vector<vector<int>> factor(2e5 + 5);
void pre() {
    for (int i = 1; i <= 2e5; i++) {
        int t = i;
        while (t <= 2e5) {
            factor[t].push_back(i);
            t += i;
        }
    }
}
void work() {
    int now_bad = 0;
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), num(n + 4), nowbad_to_ans(n + 5);
    nowbad_to_ans[0] = n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {
            for (auto j : factor[i]) {
                nowbad_to_ans[num[j]]--;
                num[j]++;
                nowbad_to_ans[num[j]]++;
            }
            now_bad++;
        }
    }
    cout << nowbad_to_ans[now_bad] << endl;
    while (q--) {
        int p, v;
        cin >> p >> v;
        int u = a[p];
        if (p != n && u > a[p + 1] && v <= a[p + 1]) {
            for (auto j : factor[p]) {
                nowbad_to_ans[num[j]]--;
                num[j]--;
                nowbad_to_ans[num[j]]++;
            }
            now_bad--;
        } else if (p != n && u <= a[p + 1] && v > a[p + 1]) {
            for (auto j : factor[p]) {
                nowbad_to_ans[num[j]]--;
                num[j]++;
                nowbad_to_ans[num[j]]++;
            }
            now_bad++;
        }
        if (p != 1 && a[p - 1] > u && a[p - 1] <= v) {
            for (auto j : factor[p - 1]) {
                nowbad_to_ans[num[j]]--;
                num[j]--;
                nowbad_to_ans[num[j]]++;
            }
            now_bad--;
        } else if (p != 1 && a[p - 1] <= u && a[p - 1] > v) {
            for (auto j : factor[p - 1]) {
                nowbad_to_ans[num[j]]--;
                num[j]++;
                nowbad_to_ans[num[j]]++;
            }
            now_bad++;
        }
        a[p] = v;
        cout << nowbad_to_ans[now_bad] << endl;
    }
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}