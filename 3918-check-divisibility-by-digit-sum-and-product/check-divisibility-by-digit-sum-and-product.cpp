class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        long long sum = 0;
        long long prod = 1;
        
        while (temp > 0) {
            int d = temp % 10;
            sum += d;
            prod *= d;
            temp /= 10;
        }
        
        long long total = sum + prod;
        return (total != 0) && (n % total == 0);
    }
};