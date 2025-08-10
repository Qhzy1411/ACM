#include <stdio.h>
#define N 1010 // 边界值通常略大于数据范围
struct OPE     // 存放干员代号和DPS数据
{
    char name[32];
    int dps;
} ope[N], temp; // temp用来作为冒泡排序的中间变量
void work() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", ope[i].name, &ope[i].dps);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 2; j >= i; j--) {
            if (ope[j + 1].dps > ope[j].dps) { // 冒泡按DPS降序排序
                temp = ope[j + 1];
                ope[j + 1] = ope[j];
                ope[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i < 5) {
            printf("%s\n", ope[i].name); // 输出前min(5,n)名干员的代号
        }
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