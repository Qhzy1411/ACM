// Author: QHZY
// Create_Time: 2025/07/18 12:13:49
#include <bits/stdc++.h>
using ll = long long;
#define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll N = 1e6;
void work() {
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    vector<int> k, pre;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        p[a[i]] = i;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        k.clear();
        k.resize(n + 1);
        pre.clear();
        pre.resize(n + 1);
        for (int j = 1; j <= n; j++) {
            if (a[j] < i)
                k[j] = -1;
            else if (a[j] > i)
                k[j] = 1;
            else
                k[j] = 0;
        }
        pre[0] = 0;
        for (int j = 1; j <= n; j++)
            pre[j] = pre[j - 1] + k[j];
        vector<int> count0(2 * n + 2), count1(2 * n + 2), sum0(2 * n + 2), sum1(2 * n + 2);
        for (int l = 0; l < p[i]; l++) {
            if (l % 2 == 1) {
                count1[pre[l] + n]++;
                sum1[pre[l] + n] += l;
            } else {
                count0[pre[l] + n]++;
                sum0[pre[l] + n] += l;
            }
        }
        int curr = 0;
        for (int r = p[i]; r <= n; r++) {
            int sum, count;
            if (r % 2 == 1) {
                count = count0[pre[r] + n];
                sum = sum0[pre[r] + n];
            } else {
                count = count1[pre[r] + n];
                sum = sum1[pre[r] + n];
            }
            curr += r * (count + sum);
        }
        ans += i * curr;
    }
    cout << ans << endl;
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