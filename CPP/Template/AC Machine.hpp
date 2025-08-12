#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) x.begin(), x.end()
#define size(x) int(x.size())
#define eb emplace_back

// AC自动机 时间：O(n)
constexpr int N = 2e5 + 6;    // 模式串个数
constexpr int LEN = 2e6 + 6;  // 文本串长度
constexpr int SIZE = 2e5 + 6; // 模式串长度总和
namespace AC {
    struct Node {
        int son[26];
        int ans;
        int fail;
        int idx;

        void init() {
            memset(son, 0, sizeof(son));
            ans = idx = fail = 0;
        }
    } tr[SIZE];

    int tot;
    int ans[N], pidx;

    vi g[SIZE]; // fail 树

    void init() {
        for (int i = 0; i <= tot; i++) {
            g[i].clear();
            tr[i].init();
        }
        tot = pidx = 0;
        memset(ans, 0, sizeof(ans));
    }

    void insert(string s, int &idx) {
        int u = 0;
        for (int i = 0; s[i]; i++) {
            int &son = tr[u].son[s[i] - 'a'];
            if (!son)
                son = ++tot, tr[son].init();
            u = son;
        }
        // 由于有可能出现相同的模式串，需要将相同的映射到同一个编号
        if (!tr[u].idx)
            tr[u].idx = ++pidx; // 第一次出现，新增编号
        idx = tr[u].idx;        // 这个模式串的编号对应这个结点的编号
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++)
            if (tr[0].son[i]) {
                q.push(tr[0].son[i]);
                g[0].push_back(tr[0].son[i]); // 不要忘记这里的 fail
            }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (tr[u].son[i]) {
                    tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                    g[tr[tr[u].fail].son[i]].push_back(tr[u].son[i]); // 记录 fail 树
                    q.push(tr[u].son[i]);
                } else
                    tr[u].son[i] = tr[tr[u].fail].son[i];
            }
        }
    }

    void query(string t) {
        int u = 0;
        for (int i = 0; t[i]; i++) {
            u = tr[u].son[t[i] - 'a'];
            tr[u].ans++;
        }
    }

    void dfs(int u) {
        for (int v : g[u]) {
            dfs(v);
            tr[u].ans += tr[v].ans;
        }
        ans[tr[u].idx] = tr[u].ans;
    }
} // namespace AC

void work() {
    AC::init();
    int n;
    cin >> n;
    vi idx(n);
    string s;
    for (int i = 0; i < n; i++) { // 插入n个模式串
        cin >> s;
        AC::insert(s, idx[i]);
        AC::ans[i] = 0;
    }
    AC::build();
    cin >> s;
    AC::query(s); // 目标串查询、DFS
    AC::dfs(0);
    for (int i = 0; i < n; i++)
        cout << AC::ans[idx[i]] << endl; // 输出每个模式串的数量
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        work();
    return 0;
}