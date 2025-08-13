#include <bits/stdc++.h>
#define int long long
using namespace std;

// 容易发现，对于1，尽可能推到后面一定是不劣的
void solve() {
    int n;
    cin >> n;
    vector<char> s(n);
    for (auto &i : s)
        cin >> i;
    if (s[n - 1] == '0' && s[n - 2] == '0') {
        cout << "Yes\n";
        return;
    }
    if (n == 3) {
        cout << "No\n";
        return;
    }
    for (int l = 0, r; l < n - 2; l++) {
        if (s[l] != '1')
            continue;
        r = l + 1;
        int cnt = 1;
        while (r < n - 2 && r - l + 1 <= cnt * 2) {
            cnt += s[r] == '1';
            r += 1;
        }
        for (int i = l; i < r; i++)
            s[i] = '0';
        int used = 0;
        for (int i = l; i < r; i += 2) {
            used += 1;
            s[i] = '1';
        }
        for (int i = r - 1; i >= l; i--) {
            if (s[i] == '1')
                continue;
            if (used == cnt)
                break;
            s[i] = '1';
            used += 1;
        }
        l = r - 1;
    }
    if (s[n - 3] == '1' && s[n - 4] == '1') {
        cout << "Yes\n";
    } else if (s[n - 3] == '0' && s[n - 4] == '0') {
        cout << "No\n";
    } else if (s[n - 4] == '1' && s[n - 3] == '0') {
        if (s[n - 2] == '0' && s[n - 1] == '1')
            cout << "No\n";
        else
            cout << "Yes\n";
    } else if (n >= 5 && s[n - 5] == '1')
        cout << "Yes\n";
    else
        cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve();
    return 0;
}