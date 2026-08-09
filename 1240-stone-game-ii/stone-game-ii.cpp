#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int memo[101][201];
    vector<int> suffixSum;
    int n;

    int solve(int i, int M, const vector<int>& piles) {
        // If we have reached or passed the end of the piles, no stones left
        if (i >= n) return 0;
        
        // If we can take all remaining piles, take them all
        if (n - i <= 2 * M) {
            return suffixSum[i];
        }
        
        // Return memoized result if available
        if (memo[i][M] != -1) {
            return memo[i][M];
        }

        int maxStones = 0;
        
        // Try all possible choices of X from 1 to 2*M
        for (int X = 1; X <= 2 * M; ++X) {
            // Stones current player gets from current choice + whatever is left 
            // minus what the opponent can get in the next optimal state
            int opponentStones = solve(i + X, max(M, X), piles);
            int currentStones = suffixSum[i] - opponentStones;
            
            maxStones = max(maxStones, currentStones);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(memo, -1, sizeof(memo));
        
        // Precompute suffix sums
        suffixSum = piles;
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] += suffixSum[i + 1];
        }
        
        // Alice starts at index 0 with M = 1
        return solve(0, 1, piles);
    }
};