class Solution {
public:
    using int64 = long long;

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        vector<pair<long long,int>> subsets;

        // Precompute LCM for every non-empty subset
        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    long long g = gcd(l, (long long)coins[i]);
                    if (l > LLONG_MAX / (coins[i] / g)) {
                        ok = false;
                        break;
                    }
                    l = l / g * coins[i];
                }
            }
            if (ok)
                subsets.push_back({l, __builtin_popcount(mask)});
        }

        auto count = [&](long long x) {
            long long res = 0;
            for (auto &[l, bits] : subsets) {
                if (l > x) continue;
                if (bits & 1)
                    res += x / l;
                else
                    res -= x / l;
            }
            return res;
        };

        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};