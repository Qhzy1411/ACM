// Author: QHZY
// Create_Time: 2025/07/21 12:46:04
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld
using pii = pair<int, int>;
using piii = pair<int, pii>;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll N = 1e6;
struct FenwickTree {
    int size;
    vector<int> tree;
    FenwickTree(int n) : size(n), tree(n + 2, 0) {}
    void update(int idx, int delta = 1) {
        while (idx <= size) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }
    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};
bool com(piii &a, piii &b) {
    if (a.second.first != b.second.first) {
        return a.second.first > b.second.first;
    } else {
        return a.second.second > b.second.second;
    }
}
void work() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> posa(n + 1), posb(n + 1);
    for (int i = 0; i < n; i++) {
        posa[a[i]] = i + 1;
        posb[b[i]] = i + 1;
    }
    vector<piii> points; // i,x,y
    for (int i = 1; i <= n; i++) {
        piii temp({i, {posa[i], posb[i]}});
        points.emplace_back(temp);
    }
    sort(points.begin(), points.end(), com);
    FenwickTree ft(n);
    vector<int> count(n + 1);
    for (auto &[i, t] : points) {
        auto y = t.second;
        count[i] = ft.query(n) - ft.query(y - 1) + 1;
        ft.update(y);
    }
    for (int i = 1; i <= n; i++) {
        cout << n - count[i] << " ";
    }
    cout << endl;
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