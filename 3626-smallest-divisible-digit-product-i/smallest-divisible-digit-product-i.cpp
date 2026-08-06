#include <string>
class Solution {
public:
    int smallestNumber(int n, int t) {
        int current=n;
        while(true){
            // Calculate the product of the digits of 'current'
            int product=1;
            string s= to_string(current);
            for(char c:s){
                product*=(c -'0');
            }

            if (product%t==0){
                return current;
            }
            // Otherwise, check the next number
            current++;
        }
        

        
    }
};