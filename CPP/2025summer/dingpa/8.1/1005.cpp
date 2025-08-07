// Create_Time: 2025/08/01 15:21:29
#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = int;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned int;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using f128 = long double;

using ll = long long;
#define int ll
using ull = unsigned int;
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
int get_val(const vector<int> &vec, int index) {
    if (index < vec.size()) {
        return vec[index];
    }
    return 0;
}
void work() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vi v1, v2, v3, v4;
    int k;
    cin >> k;
    v1.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> v1[i];
    cin >> k;
    v2.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> v2[i];
    cin >> k;
    v3.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> v3[i];
    cin >> k;
    v4.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> v4[i];
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    sort(v3.rbegin(), v3.rend());
    sort(v4.rbegin(), v4.rend());
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    int ans = 0;
    for (int i = 0; i < a; ++i) {
        if (p1 < v1.size()) {
            ans += v1[p1++];
        }
    }
    for (int i = 0; i < b; ++i) {
        int v_opt1 = get_val(v2, p2);
        int v_opt2 = get_val(v1, p1) + get_val(v1, p1 + 1);
        if (v_opt1 == 0 && v_opt2 == 0)
            continue;
        if (v_opt1 >= v_opt2) {
            ans += v_opt1;
            p2++;
        } else {
            ans += v_opt2;
            p1 += 2;
        }
    }
    for (int i = 0; i < c; ++i) {
        int v_opt1 = get_val(v3, p3);
        int v_opt2 = get_val(v2, p2) + get_val(v1, p1);
        int v_opt3 = get_val(v1, p1) + get_val(v1, p1 + 1) + get_val(v1, p1 + 2);
        if (v_opt1 == 0 && v_opt2 == 0 && v_opt3 == 0)
            continue;
        int max_v = max({v_opt1, v_opt2, v_opt3});
        ans += max_v;
        if (max_v == v_opt1) {
            p3++;
        } else if (max_v == v_opt2) {
            p2++;
            p1++;
        } else {
            p1 += 3;
        }
    }
    for (int i = 0; i < d; ++i) {
        int v_opt1 = get_val(v4, p4);
        int v_opt2 = get_val(v2, p2) + get_val(v2, p2 + 1);
        int v_opt3 = get_val(v2, p2) + get_val(v1, p1) + get_val(v1, p1 + 1);
        int v_opt4 = get_val(v1, p1) + get_val(v1, p1 + 1) + get_val(v1, p1 + 2) + get_val(v1, p1 + 3);
        if (v_opt1 == 0 && v_opt2 == 0 && v_opt3 == 0 && v_opt4 == 0)
            continue;
        int max_v = max({v_opt1, v_opt2, v_opt3, v_opt4});
        ans += max_v;
        if (max_v == v_opt1) {
            p4++;
        } else if (max_v == v_opt2) {
            p2 += 2;
        } else if (max_v == v_opt3) {
            p2++;
            p1 += 2;
        } else {
            p1 += 4;
        }
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