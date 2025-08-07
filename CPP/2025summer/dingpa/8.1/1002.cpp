// Author: QHZY
// Create_Time: 2025/08/01 14:06:40
#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using f128 = long double;

using ll = long long;
#define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld

using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using piii = pair<int, pii>;

#define pb push_back
#define eb emplace_back;
#define fi first
#define se second

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 0x3f3f3f3f3f3f3f3f;

/* ----- ----- ----- main ----- ----- ----- */
vi a, zheng, yu;
int n, m, k, p;
bool f(int &a, int &b) {
    return a % k > b % k;
}
bool pd(int mid) {
    if (mid * p * k < m)
        return false;
    int money = 0;
    vi a1 = a;
    vi times(n);
    int sum_times = 0;
    for (int i = 0; i < n; i++) {
        times[i] = min(mid, zheng[i]);
        a1[i] -= times[i] * k;
        money += times[i] * k;
        sum_times += times[i];
    }
    if (money >= m)
        return true;
    for (int i = 0; i < n; i++) {
        if (sum_times < p * mid && times[i] < mid) {
            sum_times++;
            money += a1[i];
        }
    }
    if (money >= m)
        return true;
    return false;
}
void work() {
    cin >> n >> m >> k >> p;
    a.resize(n);
    zheng.resize(n);
    yu.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), f);
    for (int i = 0; i < n; i++) {
        zheng[i] = a[i] / k;
        yu[i] = a[i] % k;
    }
    int l = 1, r = 1e9 + 5;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (pd(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l << endl;
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