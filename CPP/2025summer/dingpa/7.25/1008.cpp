#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void work() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    n = s.size();
    string s1 = s;
    string s2 = s;
    string s3 = s;
    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for (int i = 0; i < n; i++) {
        int tar = (i & 1) ? 1 : 0;
        if (s[i] - '0' != tar) {
            if (i < n - 1 && s[i + 1] - '0' == tar)
                swap(s[i], s[i + 1]);
            else
                s[i] = tar + '0';
            ans1++;
        }
    }
    for (int i = 0; i < n; i++) {
        int tar = (i & 1) ? 0 : 1;
        if (s1[i] - '0' != tar) {
            if (i < n - 1 && s1[i + 1] - '0' == tar)
                swap(s1[i], s1[i + 1]);
            else
                s1[i] = tar + '0';
            ans2++;
        }
    }
    for (int i = n; i > 0; i--) {
        int tar = (i & 1) ? 1 : 0;
        if (s2[i % n] - '0' != tar) {
            if (i > 1 && s2[i - 1] - '0' == tar)
                swap(s2[i % n], s2[i - 1]);
            else
                s2[i % n] = tar + '0';
            ans3++;
        }
    }
    for (int i = n; i > 0; i--) {
        int tar = (i & 1) ? 0 : 1;
        if (s3[i % n] - '0' != tar) {
            if (i > 1 && s3[i - 1] - '0' == tar)
                swap(s3[i % n], s3[i - 1]);
            else
                s3[i % n] = tar + '0';
            ans4++;
        }
    }
    cout << min({ans1, ans2, ans3, ans4}) << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}