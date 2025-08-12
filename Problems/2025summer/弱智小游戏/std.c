#include <stdio.h>
int main() {
    int n, k;
    long long s = 0, mod = 1e9 + 7; // s为当前分数
    scanf("%d%d\n", &n, &k);
    for (int i = 1; i <= n; i++) {
        long long md = 0;
        for (int j = 1; j <= k; j++) { // 遍历k个门，找出增量最大的门
            char x;
            scanf("%c ", &x);
            long long d;
            scanf("%lld\n", &d);
            if (x == '*') {
                if (md < s * (d - 1) % mod) { //*号门增量为s*d-s
                    md = s * (d - 1) % mod;
                }
            } else { //+号门增量为d
                if (md < d) {
                    md = d;
                }
            }
        }
        s += md; // 增加分数，取模
        s %= mod;
    }
    printf("%lld", s);
    return 0;
}
