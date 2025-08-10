#include <stdio.h>
typedef long long ll;
ll jiec[100001]; // 预处理阶乘，用ll存储
int mod = 1e9 + 7;
int main() {
    int t;
    scanf("%d", &t);
    jiec[0] = jiec[1] = 1;
    for (int i = 2; i <= 100000; i++) {
        jiec[i] = jiec[i - 1] * i;
        jiec[i] %= mod;
    }
    while (t--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", jiec[x]);
    }
    return 0;
}