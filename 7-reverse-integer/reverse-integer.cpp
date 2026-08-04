class Solution {
public:
    int reverse(int x) {
        long long ans = 0; // Use long long to safely catch overflow during multiplication
        
        while (x != 0) {
            int digit = x % 10;   // Get the last digit
            ans = ans * 10 + digit; // Append the digit to our reversed number
            x /= 10;              // Remove the last digit from x
        }
        
        // Check if the reversed number exceeds 32-bit signed integer limits
        if (ans < INT_MIN || ans > INT_MAX) {
            return 0;
        }
        
        return static_cast<int>(ans);
    }
};