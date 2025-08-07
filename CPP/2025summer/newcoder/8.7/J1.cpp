#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
// #define double ld
const int INF = 1e18;
const double PI = 3.1415926535897932;
void fft(vector<complex<double>> &a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;
    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (int i = 0, j = 0; i < n; i += 2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double angle = 2 * PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn(cos(angle), sin(angle));
    for (int i = 0; i < n / 2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = round(fa[i].real());
    }
    // 去掉前导零
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int siz = s.size();
        vector<int> a(siz);
        for (int i = 0; i < siz; i++) {
            a[i] = s[i] - '0';
        }
        cin >> s;
        reverse(s.begin(), s.end());
        siz = s.size();
        vector<int> b(siz);
        for (int i = 0; i < siz; i++) {
            b[i] = s[i] - '0';
        }
        vector<int> c = multiply(a, b);
        for (int i = 0; i < c.size(); i++) {
            if (i + 4 >= c.size() && c[i]) {
                int times = i + 5 - c.size();
                while (times--)
                    c.push_back(0);
            }
            if (c[i] >= 4) {
                c[i + 4] += c[i] / 4;
                c[i] %= 4;
            }
            if (c[i] >= 2) {
                if (c[i + 2] == 1) {
                    c[i + 2] = 0;
                } else {
                    c[i + 2]++;
                    c[i + 4]++;
                }
                c[i] -= 2;
            }
        }
        int high = c.size() - 1;
        while (c[high] != 1 && high != 0)
            high--;
        for (int i = high; i >= 0; i--)
            cout << c[i];
        cout << endl;
    }
    return 0;
}