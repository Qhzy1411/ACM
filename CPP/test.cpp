#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 5e5 + 5;

int pow2[MAX_N]; // Precompute powers of 2 modulo MOD

void precompute_pow2() {
    pow2[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
}

void solve() {
    int T;
    cin >> T;
    
    precompute_pow2();
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        int k = 0; // Count of -1's
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == -1) {
                k++;
            }
        }
        
        long long total = 0;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                continue;
            } else if (a[i] == 1) {
                if (i == 0) {
                    total = (total + pow2[k]) % MOD;
                } else {
                    if (a[i - 1] == 0) {
                        total = (total + pow2[k]) % MOD;
                    } else if (a[i - 1] == 1) {
                        // No contribution
                    } else { // a[i - 1] == -1
                        total = (total + pow2[k - 1]) % MOD;
                    }
                }
            } else { // a[i] == -1
                if (i == 0) {
                    total = (total + pow2[k - 1]) % MOD;
                } else {
                    if (a[i - 1] == 0) {
                        total = (total + pow2[k - 1]) % MOD;
                    } else if (a[i - 1] == 1) {
                        // No contribution
                    } else { // a[i - 1] == -1
                        if (k >= 2) {
                            total = (total + pow2[k - 2]) % MOD;
                        }
                        // Else, no contribution (k < 2)
                    }
                }
            }
        }
        
        cout << total << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}