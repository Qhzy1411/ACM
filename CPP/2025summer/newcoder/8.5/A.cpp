// Author: QHZY
// Create_Time: 2025/08/05 14:59:05
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

int counter(const vi &arr) {
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}
void work() {
    int id, m, k, n;
    cin >> id >> m >> k >> n;
    string ans = "";
    for (int i = 0; i < m; i++) {
        bool broken = false;
        for (int j = 0; j < k; j++) {
            vi toy(n * n);
            for (int x = 0; x < n * n; x++) {
                cin >> toy[x];
            }
            if (broken) {
                continue;
            }
            ll count = counter(toy);
            if (count & 1) {
                broken = true;
            }
        }
        if (broken) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        work();
    return 0;
}