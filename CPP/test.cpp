#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const int MOD = 998244353;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool run(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); // 检测是否为闰年
}
int getday(int y, int m) {   // 获取当前年份和月份下的最大日期
    if (m == 2 && run(y))
        return 29;
    return days[m - 1];
}

void work() {
    int n;     cin >> n;      string s;      cin >> s;       int ans = 0;
    vi dp1(10), dp2(100), dp3(1000), dp4(2); // 1 为闰年，0 非闰年
    vvi dp5(2, vi(2)), dp6(2, vi(13));                // 月份使用1-based
    vvvi dp7(2, vvi(13, vi(4)));
    for (char sc : s) {       // 遍历 S 
        int c = sc - '0'; // 将char转换为对应数字 
        // 7位向8位转移
        for(int y=0;y<2;y++){   // 遍历年份
            for(int m=1;m<13;m++){ // 遍历月份
                for(int d1=0;d1<4;d1++){ // 遍历日期第一位
                    if (dp7[y][m][d1] == 0)     continue; // 若为0直接跳过
                    int d = d1 * 10 + c; // 得到对应的当前日期
                    if (d >= 1 && d <= getday((y == 1) ? 4 : 1, m)) { // 当前日期需要大于1，小于最大日期
                        ans = (ans + dp7[y][m][d1]) % MOD; // 合法的答案转移到ans中
                    }}}}
        // 6位向7位转移
        for(int y=0;y<2;y++){   // 遍历年份
            for(int m=1;m<13;m++){ // 遍历月份               
                if (dp6[y][m] == 0)      continue; // 若为0直接跳过
                if ((c >= 0 && c <= 2) || (c == 3 && m != 2)) { // 当前月份为2月时日期第一位只能是0-2
                    dp7[y][m][c] = (dp7[y][m][c] + dp6[y][m]) % MOD; }}} // 非2月时只能是0-3
        // 5位向6位转移
        for(int y=0;y<2;y++){   // 遍历年份
            for(int m1=0;m1<2;m1++){ // 遍历月份第一位               
                if (dp5[y][m1] == 0)    continue; // 若为0直接跳过
                int m = m1 * 10 + c; // 得到对应的当前月份
                if (m >= 1 && m <= 12) { // 月份只能是0-12（其实这里可以进一步优化，将月份压缩成3种）
                    dp6[y][m] = (dp6[y][m] + dp5[y][m1]) % MOD; }}}
        // 4位向5位转移
        for(int y=0;y<2;y++){   // 遍历年份
            if (dp4[y] == 0)     continue; // 若为0直接跳过
            if (c <= 1) { dp5[y][c] = (dp5[y][c] + dp4[y]) % MOD; }} // 月份第一位只能是0/1
        // 3位向4位转移
        for(int y3=0;y3<1000;y3++){ // 遍历前3位年份
            if (dp3[y3] == 0)   continue; // 若为0直接跳过
            if (y3 == 0 && c == 0)    continue; // 年份不能为0000
            int y = run((y3 * 10 + c) % 400) ? 1 : 0; // 得到对应的当前年份，压缩为是否闰年两种状态
            dp4[y] = (dp4[y] + dp3[y3]) % MOD;}
        // 2位向3位转移
        for(int y2=0;y2<100;y2++){ // 遍历前2位年份
            if (dp2[y2] == 0)   continue; // 若为0直接跳过
            dp3[y2 * 10 + c] = (dp3[y2 * 10 + c] + dp2[y2]) % MOD;}
        // 1位向2位转移
        for(int y1=0;y1<10;y1++){ // 遍历前1位年份
            if (dp1[y1] == 0)   continue; // 若为0直接跳过
            dp2[y1 * 10 + c] = (dp2[y1 * 10 + c] + dp1[y1]) % MOD;}
        dp1[c] = (dp1[c] + 1) % MOD; // 第1位可以是任何值，直接+1
    }
    cout << ans << endl; } 
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