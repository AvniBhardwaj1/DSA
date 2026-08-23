class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        double sum_diff = 0; // Represents (S1 - S2) + (Q1 - Q2) * 4.5
        
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                sum_diff += 4.5;
            } else {
                sum_diff += (num[i] - '0');
            }
        }
        
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                sum_diff -= 4.5;
            } else {
                sum_diff -= (num[i] - '0');
            }
        }
        
        // Alice wins if the effective balanced sum difference is non-zero
        return sum_diff != 0.0;
    }
};