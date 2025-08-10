#include <stdio.h>
#define N 52 // 边界值通常略大于数据范围
int max(int a, int b) {
    return a > b ? a : b; // 取最大值
}
int min(int a, int b) {
    return a < b ? a : b; // 取最小值
}
int abs(int a) {
    return a > 0 ? a : -a; // 取绝对值
}
void work() {
    int n, m, k;
    int mindis = N, dis; // 警卫和刺杀目标的切比雪夫距离的最小值
    int map[N][N];       // 存地图
    int x, y;            // 存刺杀目标的坐标
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]); // 1-based读入地图
            if (map[i][j] == 2) {
                x = i, y = j; // 刺杀目标的坐标
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 1) {                  // 对于每一个警卫，计算他和刺杀目标的切比雪夫距离
                dis = max(abs(i - x), abs(j - y)); // 计算切比雪夫距离
                mindis = min(mindis, dis);         // 更新切比雪夫距离的最小值
            }
        }
    if (mindis > k) // 若切比雪夫最小值大于k则刺杀成功
        printf("Yes\n");
    else // 否则失败
        printf("No\n");
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