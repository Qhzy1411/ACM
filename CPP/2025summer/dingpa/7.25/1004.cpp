#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void work() {
    vector<int> a(13), zheng(13), yu(13);
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < 13; i++) {
        zheng[i] = a[i] / 3;
        yu[i] = a[i] % 3;
    }
    int ans = 0;
    for (int i = 0; i < 13; i++) {
        while (yu[i]--) {
            int max_loc = -1;
            for (int j = 0; j < 13; j++) {
                if (j == i)
                    continue;
                if (max_loc == -1)
                    max_loc = j;
                else if (zheng[j] > zheng[max_loc])
                    max_loc = j;
                else if (zheng[j] == zheng[max_loc] && yu[j] > yu[max_loc])
                    max_loc = j;
            }
            if (zheng[max_loc] == 0) {
                cout << ans << endl;
                return;
            }
            zheng[max_loc]--;
            ans++;
        }
    }
    int max_loc = -1, sum = 0;
    for (int j = 0; j < 13; j++) {
        if (max_loc == -1)
            max_loc = j;
        else if (zheng[j] > zheng[max_loc])
            max_loc = j;
        sum += zheng[j];
    }
    int other = sum - zheng[max_loc];
    if (zheng[max_loc] >= 3 * other) {
        ans += other * 3;
        cout << ans << endl;
        return;
    }
    ans += sum / 4 * 3;
    if (sum % 4 == 3)
        ans += 2;
    else if (sum % 4 == 2)
        ans += 1;
    cout << ans << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}