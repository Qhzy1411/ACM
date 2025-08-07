#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using f128 = long double;

using ll = long long;
#define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld

using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using piii = pair<int, pii>;

#define pb push_back
#define eb emplace_back;
#define fi first
#define se second

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

/* ----- ----- ----- main ----- ----- ----- */

int qmi(int base, int exp) {
    i128 res = 1;
    i128 b = base;
    while (exp > 0) {
        if (exp & 1)
            res = res * b % mod;
        b = b * b % mod;
        exp >>= 1;
    }
    return (int)res;
}
int mul(int a, int b, int m) {
    return (int)((i128)a * b % m);
}
bool is_prime(int n) {
    if (n < 2)
        return false;
    static const int bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    int d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    for (int a : bases) {
        if (a >= n)
            break;
        i128 x = qmi(a, d);
        if (x == 1 || x == n - 1)
            continue;
        bool flag = true;
        for (int r = 1; r < s; ++r) {
            x = x * x % n;
            if (x == n - 1) {
                flag = false;
                break;
            }
        }
        if (flag)
            return false;
    }
    return true;
}
int f(int x, int c, int n) {
    return (int)(((i128)x * x + c) % n);
}
int pollard(int n) {
    if (n % 2 == 0)
        return 2;
    if (is_prime(n))
        return n;
    int x = 0, y = 0, d = 1;
    int c = rng() % (n - 1) + 1;
    while (d == 1) {
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        d = __gcd(abs(x - y), n);
    }
    if (d == n)
        return pollard(n);
    return d;
}
void factorize(int n, map<int, int> &factors) {
    if (n <= 1)
        return;
    if (is_prime(n)) {
        factors[n]++;
        return;
    }
    int p = pollard(n);
    factorize(p, factors);
    factorize(n / p, factors);
}
int counter(int num, int p) {
    if (p == 0 || p == 1)
        return 0;
    int count = 0;
    while (num > 0 && num % p == 0) {
        count++;
        num /= p;
    }
    return count;
}
void work() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int gc = __gcd(a, c);
    if (gc == 1) {
        cout << 1 << endl;
        return;
    }
    map<int, int> primes;
    factorize(gc, primes);
    int ans = 1;
    for (auto &[p, t] : primes) {
        int counta = counter(a, p);
        int countb = counter(c, p);
        i128 exp = min((i128)b * counta, (i128)d * countb);
        int exp2 = exp % (mod - 1);
        int term = qmi(p, exp2);
        ans = (i128)ans * term % mod;
    }
    cout << ans << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        work();
    return 0;
}