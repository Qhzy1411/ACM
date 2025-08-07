// Author: QHZY
// Create_Time: 2025/08/06 13:47:45
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
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
vector<int> KMP(string text, string pattern) {
    string cur = pattern + '#' + text;
    int sz1 = text.size(), sz2 = pattern.size();
    vector<int> v;
    vector<int> lps = prefix_function(cur);
    for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
        if (lps[i] == sz2)
            v.push_back(i - 2 * sz2);
    }
    return v;
}
void work() {
    int n, k;
    cin >> n >> k;
    string s, pat = "nanjing";
    cin >> s;
    if (n < 7) {
        cout << 0 << endl;
        return;
    }
    vi ans = KMP(s, pat);
    int ansc = ans.size();
    for (int i = 1; i <= min(k, (ll)6); i++) {
        bool flag = true;
        for (int j = 0; j < 7; j++)
            if (s[(n - 7 + i + j) % n] != pat[j]) {
                flag = false;
            }
        if (flag) {
            ansc++;
            break;
        }
    }
    cout << ansc << endl;
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