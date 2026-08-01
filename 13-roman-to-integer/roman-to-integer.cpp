class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        int total = 0;
        
        // Loop through every character in the string
        for (int i = 0; i < s.size(); i++) {
            // If the current numeral is smaller than the next one, subtract it
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } 
            // Otherwise, add it
            else {
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};