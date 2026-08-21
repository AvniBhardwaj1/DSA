class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        // Helper to compute number of valid multiples <= m
        auto countMultiples = [&](long long m) -> long long {
            long long cnt = 0;
            int totalSubsets = 1 << n;
            
            for (int mask = 1; mask < totalSubsets; ++mask) {
                long long currentLcm = 1;
                int bits = 0;
                
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        bits++;
                        currentLcm = std::lcm(currentLcm, (long long)coins[i]);
                        // If LCM exceeds m, floor(m / LCM) is 0
                        if (currentLcm > m) break;
                    }
                }
                
                if (currentLcm <= m) {
                    if (bits % 2 == 1) {
                        cnt += m / currentLcm;
                    } else {
                        cnt -= m / currentLcm;
                    }
                }
            }
            return cnt;
        };

        long long left = 1;
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long right = minCoin * k;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (countMultiples(mid) >= k) {
                ans = mid;
                right = mid - 1; // Try to find a smaller valid amount
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};