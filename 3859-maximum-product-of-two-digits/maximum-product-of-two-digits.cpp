#include <string>
#include <algorithm>
// #include <max>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int maxProd = 0;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                // Convert char to actual integer by subtracting '0'
                // When you subtract '0' from any character digit, you get its exact integer value instantly in O(1) time with zero overhead:
                // '3' - '0' → 51 - 48 = 3.
                int prod = (s[i] - '0') * (s[j] - '0');
                maxProd = max(maxProd, prod);
            }
        }
        
        return maxProd;
    }
};