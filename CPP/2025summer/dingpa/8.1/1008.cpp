// Author: QHZY
// Create_Time: 2025/08/01 14:41:15
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
const int N = 1e6 + 7;

/* ----- ----- ----- main ----- ----- ----- */

namespace AC {
    struct Node {
        int son[26];
        int fail;
        int minlen;
    };
    Node tr[N];
    int tot;

    void init() {
        for (int i = 0; i <= tot; ++i) {
            memset(tr[i].son, 0, sizeof(tr[i].son));
            tr[i].fail = 0;
            tr[i].minlen = 0;
        }
        tot = 0;
        tr[0].minlen = INF;
    }
    void insert(const string &s) {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (!tr[u].son[c]) {
                tr[u].son[c] = ++tot;
                tr[tot].minlen = INF;
            }
            u = tr[u].son[c];
        }
        tr[u].minlen = min(tr[u].minlen, (int)s.length());
    }
    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (tr[0].son[i]) {
                q.push(tr[0].son[i]);
            }
        }
        vi order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int i = 0; i < 26; ++i) {
                if (tr[u].son[i]) {
                    tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                    q.push(tr[u].son[i]);
                } else {
                    tr[u].son[i] = tr[tr[u].fail].son[i];
                }
            }
        }
        for (int u : order) {
            tr[u].minlen = min(tr[u].minlen, tr[tr[u].fail].minlen);
        }
    }
    void query(const string &t, vi &res) {
        res.assign(t.length(), INF);
        int u = 0;
        for (int i = 0; i < t.length(); i++) {
            u = tr[u].son[t[i] - 'a'];
            res[i] = tr[u].minlen;
        }
    }
}

int n;
vi lb, le; // begin,end

vi queries[N];
int bit[N];
void update(int idx, int val) {
    for (++idx; idx <= n + 1; idx += idx & -idx)
        bit[idx] += val;
}
int query(int idx) {
    int sum = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

void work() {
    int l, r;
    cin >> l >> r;
    vector<string> pre(l), suf(r);
    for (int i = 0; i < l; i++)
        cin >> pre[i];
    for (int i = 0; i < r; i++)
        cin >> suf[i];
    string s;
    cin >> s;
    n = s.length();

    AC::init();
    for (string &p : pre) {
        if (p.length() <= n) {
            reverse(p.begin(), p.end());
            AC::insert(p);
        }
    }
    AC::build();
    string s_r = s;
    reverse(s_r.begin(), s_r.end());
    vi lb_r;
    AC::query(s_r, lb_r);
    lb.assign(n, INF);
    for (int i = 0; i < n; i++) {
        lb[i] = lb_r[n - 1 - i];
    }

    AC::init();
    for (const string &s : suf) {
        if (s.length() <= n) {
            AC::insert(s);
        }
    }
    AC::build();
    AC::query(s, le);

    for (int i = 0; i <= n; ++i) {
        queries[i].clear();
        bit[i] = 0;
    }
    bit[n + 1] = 0;
    for (int j = 0; j < n; ++j) {
        if (le[j] != INF) {
            int limit = j - le[j] + 1;
            if (limit >= 0) {
                queries[limit].push_back(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (lb[i] != INF) {
            int req = i + lb[i] - 1;
            if (req < n) {
                update(req, 1);
            }
        }
        for (int j : queries[i]) {
            ans += query(j);
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