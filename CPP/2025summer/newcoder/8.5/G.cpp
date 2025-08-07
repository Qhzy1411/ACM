#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
vector<int> primes, ready;
vector<int> linearSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > n / i) { // 防止溢出并提前终止循环
                break;
            }
            isPrime[i * p] = false;
            if (i % p == 0) { // 保证每个合数被最小质因子筛除
                break;
            }
        }
    }
    return primes;
}
void pre() {
    primes = linearSieve(1000000);
    ready = primes;
    int n = primes.size();
    for (int i = 0; i < n; i++) {
        if (primes[i] * primes[i] * primes[i] > 1e6)
            break;
        for (int j = i; j < n; j++) {
            if (primes[i] * primes[j] * primes[j] > 1e6)
                break;
            for (int k = j; k < n; k++) {
                int num = primes[i] * primes[j] * primes[k];
                if (num > 1e6)
                    break;
                ready.push_back(num);
            }
        }
    }
    for (int i1 = 0; i1 < n; i1++) {
        if (primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] > 1e6)
            break;
        for (int i2 = i1; i2 < n; i2++) {
            if (primes[i1] * primes[i2] * primes[i2] * primes[i2] * primes[i2] > 1e6)
                break;
            for (int i3 = i2; i3 < n; i3++) {
                if (primes[i1] * primes[i2] * primes[i3] * primes[i3] * primes[i3] > 1e6)
                    break;
                for (int i4 = i3; i4 < n; i4++) {
                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i4] > 1e6)
                        break;
                    for (int i5 = i4; i5 < n; i5++) {
                        int num = primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5];
                        if (num > 1e6)
                            break;
                        ready.push_back(num);
                    }
                }
            }
        }
    }
    for (int i1 = 0; i1 < n; i1++) {
        if (primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] > 1e6)
            break;
        for (int i2 = i1; i2 < n; i2++) {
            if (primes[i1] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] > 1e6)
                break;
            for (int i3 = i2; i3 < n; i3++) {
                if (primes[i1] * primes[i2] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] > 1e6)
                    break;
                for (int i4 = i3; i4 < n; i4++) {
                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i4] * primes[i4] * primes[i4] > 1e6)
                        break;
                    for (int i5 = i4; i5 < n; i5++) {
                        if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i5] * primes[i5] > 1e6)
                            break;
                        for (int i6 = i5; i6 < n; i6++) {
                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i6] > 1e6)
                                break;
                            for (int i7 = i6; i7 < n; i7++) {
                                int num = primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7];
                                if (num > 1e6)
                                    break;
                                ready.push_back(num);
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i1 = 0; i1 < n; i1++) {
        if (primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] > 1e6)
            break;
        for (int i2 = i1; i2 < n; i2++) {
            if (primes[i1] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] > 1e6)
                break;
            for (int i3 = i2; i3 < n; i3++) {
                if (primes[i1] * primes[i2] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] > 1e6)
                    break;
                for (int i4 = i3; i4 < n; i4++) {
                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] > 1e6)
                        break;
                    for (int i5 = i4; i5 < n; i5++) {
                        if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i5] * primes[i5] * primes[i5] * primes[i5] > 1e6)
                            break;
                        for (int i6 = i5; i6 < n; i6++) {
                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i6] * primes[i6] * primes[i6] > 1e6)
                                break;
                            for (int i7 = i6; i7 < n; i7++) {
                                if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i7] * primes[i7] > 1e6)
                                    break;
                                for (int i8 = i7; i8 < n; i8++) {
                                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i8] > 1e6)
                                        break;
                                    for (int i9 = i8; i9 < n; i9++) {
                                        int num = primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i9];
                                        if (num > 1e6)
                                            break;
                                        ready.push_back(num);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i1 = 0; i1 < n; i1++) {
        if (primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] > 1e6)
            break;
        for (int i2 = i1; i2 < n; i2++) {
            if (primes[i1] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] > 1e6)
                break;
            for (int i3 = i2; i3 < n; i3++) {
                if (primes[i1] * primes[i2] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] > 1e6)
                    break;
                for (int i4 = i3; i4 < n; i4++) {
                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] > 1e6)
                        break;
                    for (int i5 = i4; i5 < n; i5++) {
                        if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i5] * primes[i5] * primes[i5] * primes[i5] * primes[i5] * primes[i5] > 1e6)
                            break;
                        for (int i6 = i5; i6 < n; i6++) {
                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i6] * primes[i6] * primes[i6] * primes[i6] * primes[i6] > 1e6)
                                break;
                            for (int i7 = i6; i7 < n; i7++) {
                                if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i7] * primes[i7] * primes[i7] * primes[i7] > 1e6)
                                    break;
                                for (int i8 = i7; i8 < n; i8++) {
                                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i8] * primes[i8] * primes[i8] > 1e6)
                                        break;
                                    for (int i9 = i8; i9 < n; i9++) {
                                        if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i9] * primes[i9] * primes[i9] > 1e6)
                                            break;
                                        for (int i10 = i9; i10 < n; i10++) {
                                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i9] * primes[i10] * primes[i10] > 1e6)
                                                break;
                                            for (int i11 = i10; i11 < n; i11++) {
                                                int num = primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i9] * primes[i10] * primes[i11];
                                                if (num > 1e6)
                                                    break;
                                                ready.push_back(num);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i1 = 0; i1 < n; i1++) {
        if (primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] * primes[i1] > 1e6)
            break;
        for (int i2 = i1; i2 < n; i2++) {
            if (primes[i1] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] * primes[i2] > 1e6)
                break;
            for (int i3 = i2; i3 < n; i3++) {
                if (primes[i1] * primes[i2] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] * primes[i3] > 1e6)
                    break;
                for (int i4 = i3; i4 < n; i4++) {
                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] * primes[i4] > 1e6)
                        break;
                    for (int i5 = i4; i5 < n; i5++) {
                        if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i5] * primes[i5] * primes[i5] * primes[i5] * primes[i5] * primes[i5] * primes[i5] * primes[i5] > 1e6)
                            break;
                        for (int i6 = i5; i6 < n; i6++) {
                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i6] * primes[i6] * primes[i6] * primes[i6] * primes[i6] * primes[i6] * primes[i6] > 1e6)
                                break;
                            for (int i7 = i6; i7 < n; i7++) {
                                if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i7] * primes[i7] * primes[i7] * primes[i7] * primes[i7] * primes[i7] > 1e6)
                                    break;
                                for (int i8 = i7; i8 < n; i8++) {
                                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i8] * primes[i8] * primes[i8] * primes[i8] * primes[i8] > 1e6)
                                        break;
                                    for (int i9 = i8; i9 < n; i9++) {
                                        if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i9] * primes[i9] * primes[i9] * primes[i9] * primes[i9] > 1e6)
                                            break;
                                        for (int i10 = i9; i10 < n; i10++) {
                                            if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i9] * primes[i10] * primes[i10] * primes[i10] * primes[i10] > 1e6)
                                                break;
                                            for (int i11 = i10; i11 < n; i11++) {
                                                if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i9] * primes[i10] * primes[i11] * primes[i11] * primes[i11] > 1e6)
                                                    break;
                                                for (int i12 = i11; i12 < n; i12++) {
                                                    if (primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i9] * primes[i10] * primes[i11] * primes[i12] * primes[i12] > 1e6)
                                                        break;
                                                    for (int i13 = i12; i13 < n; i13++) {
                                                        int num = primes[i1] * primes[i2] * primes[i3] * primes[i4] * primes[i5] * primes[i6] * primes[i7] * primes[i8] * primes[i9] * primes[i10] * primes[i11] * primes[i12] * primes[i13];
                                                        if (num > 1e6)
                                                            break;
                                                        ready.push_back(num);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    sort(ready.begin(), ready.end());
}
void work() {
    int n;
    cin >> n;
    for (int i = 0; i < n / 2; i++)
        cout << ready[i] << ' ';
    cout << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}