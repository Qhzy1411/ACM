#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
using namespace std;
const ll INF = 1e18;
int mod = 1e9 + 7;
ll power(ll a, ll b) {
    a %= mod;
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
int down[5005];
int fnk(int n, int k) {
    int up = 1, d = down[n], b = n, res;
    for (int i = 1; i <= b; i++) {
        up *= (n + k - i);
        up %= mod;
    }
    d = power(d, mod - 2);
    res = up * d % mod;
    return res;
}
void work() {
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int high_most = a[n - 1], now_len = 0;
    vector<pair<int, int>> qujian;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= high_most)
            now_len++;
        else {
            qujian.push_back({now_len, high_most});
            now_len = 1;
            high_most = a[i];
        }
    }
    qujian.push_back({now_len, high_most});
    if (qujian.size() == 1) {
        cout << fnk(qujian[0].first, r - qujian[0].second + 1) << endl;
        return;
    }
    n = qujian.size();
    int m = fnk(qujian[0].first, qujian[1].second - qujian[0].second + 1) - 1, len = qujian[0].first;
    m = (m + mod) % mod;
    int dis;
    for (int i = 1; i < n - 1; i++) {
        dis = qujian[i + 1].second - qujian[i].second + 1;
        len += qujian[i].first;
        m = m * (fnk(qujian[i].first, dis)) % mod + fnk(len, dis) - 1;
        m = (m + mod) % mod;
    }
    dis = r - qujian[n - 1].second + 1;
    len += qujian[n - 1].first;
    m = m * (fnk(qujian[n - 1].first, dis)) + fnk(len, dis);
    m %= mod;
    cout << m << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int now = 1;
    for (int i = 1; i <= 5003; i++) {
        now *= i;
        now %= mod;
        down[i] = now;
    }
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}