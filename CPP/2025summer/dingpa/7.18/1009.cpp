#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
using namespace std;
bool f(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
void work() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int loc = 0;
    for (auto &i : a) {
        cin >> i.second;
        i.first = loc++;
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    sort(a.begin(), a.end(), f);
    int l = a[0].first, r = a[1].first;
    if (l > r)
        swap(l, r);
    int ans = 2;
    for (int i = 2; i < n; i++) {
        if (a[i].first < l)
            l = a[i].first;
        else if (a[i].first > r)
            r = a[i].first;
        ans = max(r - l + 2 - i, ans);
    }
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