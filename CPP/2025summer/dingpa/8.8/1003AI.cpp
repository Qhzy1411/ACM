#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
        return 0;
    cout.setf(std::ios::fixed);
    for (int tc = 0; tc < T; ++tc) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];

        // check function: for given R, return pair(count, segments vector)
        auto check_count = [&](long double R, bool build_segments) {
            int cnt = 0;
            vector<pair<ll, ll>> segs; // (sumA, sumB)
            long double cur = 0.0L;
            ll suma = 0, sumb = 0;
            for (int i = 0; i < n; ++i) {
                long double vi = (long double)b[i] - R * (long double)a[i];
                cur += vi;
                suma += a[i];
                sumb += b[i];
                if (cur <= 1e-18L) { // 当段和 <= 0 时截断；容忍 tiny eps
                    cnt++;
                    if (build_segments) {
                        segs.emplace_back(suma, sumb);
                    }
                    cur = 0.0L;
                    suma = 0;
                    sumb = 0;
                }
            }
            // 如果 build_segments 要返回 segs via some reference: we'll use a global static capture via lambda return
            // But here we just want count, actual segments will be rebuilt later by calling with build_segments=true and capture via static variable.
            if (build_segments) {
                // We'll return count via packing into bits by using static storage
                // But easier: provide separate lambda later. For now just return cnt.
            }
            // Using pair<int, vector> approach is cumbersome inside lambda; instead we'll do two lambdas outside.
            return cnt;
        };

        // Binary search R in [0,1]
        long double lo = 0.0L, hi = 1.0L;
        for (int it = 0; it < 110; ++it) {
            long double mid = (lo + hi) / 2.0L;
            // compute max number of segments for mid
            int cnt = 0;
            long double cur = 0.0L;
            for (int i = 0; i < n; ++i) {
                long double vi = (long double)b[i] - mid * (long double)a[i];
                cur += vi;
                if (cur <= 0.0L + 1e-18L) {
                    cnt++;
                    cur = 0.0L;
                }
            }
            if (cnt >= k)
                hi = mid;
            else
                lo = mid;
        }
        long double R = hi; // feasible approx minimal R

        // Rebuild the segments by greedy (max count) and store integer sums
        vector<pair<ll, ll>> segs;
        {
            long double cur = 0.0L;
            ll suma = 0, sumb = 0;
            for (int i = 0; i < n; ++i) {
                long double vi = (long double)b[i] - R * (long double)a[i];
                cur += vi;
                suma += a[i];
                sumb += b[i];
                if (cur <= 0.0L + 1e-18L) {
                    segs.emplace_back(suma, sumb);
                    cur = 0.0L;
                    suma = 0;
                    sumb = 0;
                }
            }
            // If any remainder (shouldn't for feasible R), attach it
            if (suma > 0 || sumb > 0) {
                segs.emplace_back(suma, sumb);
            }
        }

        // If we have fewer than k segments (due to numeric issues), force at least 1 (shouldn't happen)
        if ((int)segs.size() < k) {
            // fallback: make every element its own segment
            segs.clear();
            for (int i = 0; i < n; ++i)
                segs.emplace_back((ll)a[i], (ll)b[i]);
        }

        // If more than k, merge adjacent from left until size == k
        while ((int)segs.size() > k) {
            // merge first two (any adjacent pair is fine)
            auto p1 = segs[0];
            auto p2 = segs[1];
            pair<ll, ll> merged = {p1.first + p2.first, p1.second + p2.second};
            // replace first two by merged
            segs.erase(segs.begin()); // remove first
            segs.erase(segs.begin()); // remove new first (original second)
            segs.insert(segs.begin(), merged);
            // continue
        }

        // Now compute the segment with maximum ratio b/a
        ll bestP = 0, bestV = 1; // store numerator, denominator
        for (auto &pr : segs) {
            ll va = pr.first;
            ll vb = pr.second;
            // Compare vb/va vs bestP/bestV by cross-multiplication
            if ((__int128)vb * bestV > (__int128)bestP * va) {
                bestP = vb;
                bestV = va;
            }
        }
        // reduce fraction
        ll g = std::gcd(bestP, bestV);
        bestP /= g;
        bestV /= g;
        cout << bestP << "/" << bestV << "\n";
    }
    return 0;
}