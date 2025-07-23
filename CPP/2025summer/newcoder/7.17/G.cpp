#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using order_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int ll
const int INF = 1e18;
const long double PI = acosl(-1);
class Point {
public:
    long double x;                     // 行坐标
    long double y;                     // 列坐标
    Point() {}                    // 默认构造函数
    Point(long double x1, long double y1) { // 重载构造函数
        x = x1;
        y = y1;
    }
    void disp() { // 输出函数
        printf("(%g, %g)", x, y);
    }
    friend Point operator+(const Point &p1, const Point &p2) { // 重载+运算符
        return Point(p1.x + p2.x, p1.y + p2.y);
    }

    friend Point operator-(const Point &p1, const Point &p2) { // 重载-运算符
        return Point(p1.x - p2.x, p1.y - p2.y);
    }

    friend long double Dot(const Point &p1, const Point &p2) { // 两个向量的点积
        return p1.x * p2.x + p1.y * p2.y;
    }
    friend long double Length(Point p);
    friend long double DistPtoSegment(Point p0, Point p1, Point p2);

    friend long double Dis(Point p1, Point p2) {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
    friend long double Det(Point p1, Point p2);                            // 两个向量的叉积
    friend int Direction(Point p0, Point p1, Point p2);            // 判断两线段p0p1和p0p2的方向
    friend bool OnSegment(Point p0, Point p1, Point p2);              // 判断点p0是否在p1p2线段上
    friend bool SegIntersect(Point p1, Point p2, Point p3, Point p4); // 判断p1p2和p3p4线段是否相交
    friend bool PointInPolygon(Point p0, vector<Point> a);            // 判断点p0是否在点集a所形成的多边形内
    friend Point PtoSegment(Point p0, Point p1, Point p2) {
        long double k1, k2;
        Point t;
        if (p1.x - p2.x == 0) {
            t.x = p1.x;
            t.y = p0.y;
            return t;
        }
        k1 = (p1.y - p2.y) / (p1.x - p2.x);
        if (k1 == 0) {
            t.x = p0.x;
            t.y = p1.y;
            return t;
        }
        k2 = -1.0 / k1;
        t.x = (p1.y - p0.y + k2 * p0.x - k1 * p1.x) / (k2 - k1);
        t.y = k2 * t.x - k2 * p0.x + p0.y;
        return t;
    }
};
long double Length(Point p) {
    return sqrt(Dot(p, p));
}
long double DistPtoSegment(Point p0, Point p1, Point p2) { // 求p0到p1p2线段的距离
    Point v1 = p2 - p1, v2 = p1 - p2, v3 = p0 - p1, v4 = p0 - p2;
    if (p1.x == p2.x && p1.y == p2.y)
        return Length(p0 - p1); // 两点重合
    if (Dot(v1, v3) < 0)
        return Length(v3);
    else if (Dot(v2, v4) < 0)
        return Length(v4);
    else
        return fabs(Det(v1, v3)) / Length(v1);
}

long double Det(const Point p1, const Point p2) { // 两个向量的叉积
    return p1.x * p2.y - p1.y * p2.x;
}
int Direction(Point p0, Point p1, Point p2) { // 判断两线段p0p1和p0p2的方向
    long double d = Det(p1 - p0, p2 - p0);
    if (fabs(d)<1e-6 )
        return 0; // p0,p1,p2三点共线
    else if (d > 0)
        return 1; // p0p1在p0p2的顺时针方向上
    else
        return -1; // p0p1在p0p2的逆时针方向上
}
bool OnSegment(Point p0, Point p1, Point p2) { // 判断点p0是否在p1p2线段上
    return fabs(Det(p1 - p0, p2 - p0)) < 1e-6 && (Dot(p1 - p0, p2 - p0) < 0||fabs(Dot(p1-p0,p2-p0))<1e-6);
}
bool SegIntersect(Point p1, Point p2, Point p3, Point p4) { // 判断p1p2和p3p4线段是否相交
    int d1, d2, d3, d4;
    d1 = Direction(p3, p1, p4); // 求p3p1在p3p4的哪个方向上
    d2 = Direction(p3, p2, p4); // 求p3p2在p3p4的哪个方向上
    d3 = Direction(p1, p3, p2); // 求p1p3在p1p2的哪个方向上
    d4 = Direction(p1, p4, p2); // 求p1p4在p1p2的哪个方向上
    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;
    if (d1 == 0 && OnSegment(p1, p3, p4)) // 若d1为0且p1在p3p4线段上
        return true;
    else if (d2 == 0 && OnSegment(p2, p3, p4)) // 若d2为0且p2在p3p4线段上
        return true;
    else if (d3 == 0 && OnSegment(p3, p1, p2)) // 若d3为0且p3在p1p2线段上
        return true;
    else if (d4 == 0 && OnSegment(p4, p1, p2)) // 若d4为0且p4在p1p2线段上
        return true;
    else
        return false;
}
bool PointInPolygon(Point p0, vector<Point> a) { // 判断点p0是否在点集a所形成的多边形内
    int cnt = 0;
    long double x;
    Point p1, p2;
    for (int i = 0; i < a.size(); ++i) {
        p1 = a[i];
        p2 = a[(i + 1) % a.size()]; // 取多边形的一条边
        if (OnSegment(p0, p1, p2))  // 如果点p0在多边形边p1p2线段上,返回true
            return true;
        // 以下求解y=p0.y与p1p2的交点
        if (fabs(p1.y - p2.y)<1e-6)
            continue; // 如果p1p2是水平线,直接跳过
        // 以下两种情况是交点在p1p2的延长线上、而非p1p2线段上
        if (p0.y < p1.y && p0.y < p2.y)
            continue; // p0在p1p2线段下方,直接跳过
        if ((p0.y > p1.y && p0.y > p2.y)||(fabs(p0.y-p1.y)<1e-6&&p0.y>p2.y)||(fabs(p0.y-p2.y)<1e-6&&p0.y>p1.y)||(fabs(p0.y-p1.y)<1e-6&&fabs(p0.y-p2.y)<1e-6))
            continue;                                             // p0在p1p2线段上方,直接跳过
        x = (p0.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x; // 求交点坐标的x值
        if (x >= p0.x)
            ++cnt; // 只统计射线的一边
    }
    return (cnt % 2 == 1);
}
Point p0;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        long double x, y;
        cin >> n;
        cin >> x >> y;
        p0.x = x, p0.y = y;
        vector<Point> a(n);
        long double maxd = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
            if (maxd < Dis(a[i], p0)) {
                maxd = Dis(a[i], p0);
            }
        }
        vector<Point> P;
        for (int i = 0; i < n; i++) {
            if (fabs(maxd - Dis(a[i], p0)) < 1e-6) {
                P.push_back(a[i]);
            }
        }
        long double maxdeg = 0;
        int s = P.size();
        for (int i = 0; i < s; i++) {
            long double temp1 = Dot(P[i] - p0, P[(i + 1) % s] - p0)*Dot(P[i] - p0, P[(i + 1) % s] - p0);
            long double temp2 = (pow(p0.x - P[(i+1)%s].x, 2) + pow(p0.y - P[(i+1)%s].y, 2))*(pow(p0.x - P[(i)%s].x, 2) + pow(p0.y - P[(i)%s].y, 2));
            long double temp = sqrt(temp1/temp2);
            if(Dot(P[i] - p0, P[(i + 1) % s] - p0)<0) temp*=-1;
            long double deg; 
            if (fabs(temp1-temp2) <1e-6){
                deg=PI*2;
            }
            else if(fabs(temp1+temp2) <1e-6){
                deg=PI;
            }
            else{
                deg = acos(temp);
                if (Det(P[i] - p0, P[(i + 1) % s] - p0) <= 0) {
                    deg =  PI*2 - deg;
                }
            }
            if (deg > maxdeg) {
                maxdeg = deg;
            }
        }
        if (!PointInPolygon(p0, a)) {
            long double maxdeg2 =  PI*2;
            maxdeg = max(maxdeg, maxdeg2);
        }
        cout << fixed << setprecision(15) << maxdeg << endl;
    }
    return 0;
}