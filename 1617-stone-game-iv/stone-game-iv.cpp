#include <vector>
#include <cstring>

class Solution {
private:
    int dp[100005]; // Adjust size based on constraints (e.g., n <= 10^5)

    bool canWin(int remainingStones) {
        // Base case: no stones left, current player loses
        if (remainingStones <= 0) {
            return false;
        }

        // Check if result is already computed
        if (dp[remainingStones] != 0) {
            return dp[remainingStones] == 1;
        }

        // Try removing each possible perfect square number of stones
        for (int k = 1; k * k <= remainingStones; ++k) {
            // If opponent loses after our move, we win
            if (!canWin(remainingStones - k * k)) {
                dp[remainingStones] = 1;  // Mark as winning position
                return true;
            }
        }

        // If no winning move found, current player loses
        dp[remainingStones] = -1;  // Mark as losing position
        return false;
    }

public:
    bool winnerSquareGame(int n) {
        // Initialize memoization table with 0 (unvisited)
        memset(dp, 0, sizeof(dp));
        return canWin(n);
    }
};