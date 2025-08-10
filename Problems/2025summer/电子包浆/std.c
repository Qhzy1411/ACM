#include <stdio.h>
void work() {
    int n;
    scanf("%d", &n);
    double a = 1, d; // a 为当前清晰度，d为清晰保留度
    while (n--) {    // n次循环
        scanf("%lf", &d);
        a *= d;
    }
    if (a < 0.3) { // 清晰度小于0.3即为包浆了
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) { // T组数据
        work();
    }
    return 0;
}