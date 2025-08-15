#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll INF = 1e18;

struct Line {
    ll a, b;
    Line(ll a = 0, ll b = 0) : a(a), b(b) {}
    ll eval(ll x) const { return a * x + b; }
};

bool bad(const Line &la, const Line &lb, const Line &lc) {
    return (lb.b - la.b) * (la.a - lc.a) >= (lc.b - la.b) * (la.a - lb.a);
}

struct ConvexHull {
    vector<Line> hull;
    void add_line(ll a, ll b) {
        Line l(a, b);
        while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull.back(), l))
            hull.pop_back();
        hull.push_back(l);
    }
    ll query(ll x) {
        if (hull.empty())
            return INF;
        int l = 0, r = hull.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (hull[m].eval(x) <= hull[m + 1].eval(x))
                r = m;
            else
                l = m + 1;
        }
        return hull[l].eval(x);
    }
};

void work() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<tuple<int, ll, ll>>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            ll t_i, w_i;
            cin >> u >> v >> t_i >> w_i;
            adj[u].emplace_back(v, t_i, w_i);
        }
        vector<vector<pll>> dist(n + 1);
        priority_queue<tuple<ll, ll, int>, vector<tuple<ll, ll, int>>, greater<>> pq;
        dist[1].emplace_back(0, 0);
        pq.emplace(0, 0, 1);
        while (!pq.empty()) {
            auto [sum_t, max_w, u] = pq.top();
            pq.pop();
            if (u == n)
                continue;
            bool skip = false;
            for (auto [s, w] : dist[u]) {
                if (s <= sum_t && w >= max_w) {
                    if (s < sum_t || w > max_w) {
                        skip = true;
                        break;
                    }
                }
            }
            if (skip)
                continue;
            for (auto [v, t_i, w_i] : adj[u]) {
                ll new_sum_t = sum_t + t_i;
                ll new_max_w = max(max_w, w_i);
                bool add = true;
                vector<pll> new_dist;
                for (auto [s, w] : dist[v]) {
                    if (s <= new_sum_t && w >= new_max_w) {
                        if (s < new_sum_t || w > new_max_w) {
                            add = false;
                            break;
                        }
                    }
                }
                if (add) {
                    vector<pll> temp;
                    bool inserted = false;
                    for (auto [s, w] : dist[v]) {
                        if (new_sum_t <= s && new_max_w >= w) {
                            continue;
                        }
                        temp.emplace_back(s, w);
                    }
                    temp.emplace_back(new_sum_t, new_max_w);
                    sort(temp.begin(), temp.end());
                    dist[v] = temp;
                    pq.emplace(new_sum_t, new_max_w, v);
                }
            }
        }
        vector<pll> paths = dist[n];
        if (paths.empty()) {
            int q;
            cin >> q;
            while (q--) {
                int k;
                cin >> k;
                cout << 0 << ' ';
            }
            cout << '\n';
            continue;
        }
        sort(paths.begin(), paths.end());
        ConvexHull ch;
        for (auto [sum_t, max_w] : paths) {
            ch.add_line(-max_w, sum_t);
        }
        int q;
        cin >> q;
        while (q--) {
            int k;
            cin >> k;
            ll res = ch.query(k);
            cout << res << endl;
        }
    }
}
int main() {
    work();
    return 0;
}