#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // This set will store the characters in our current "window"
        unordered_set<char> windowSet;
        
        // 'left' is the start index of our sliding window
        int left = 0; 
        
        // This will keep track of the maximum length we've seen so far
        int maxLength = 0; 

        // 'right' is the end index of our sliding window, expanding one by one
        for (int right = 0; right < s.size(); right++) {
            
            // If the character at 'right' is already in our set, we have a duplicate!
            // We must shrink our window from the 'left' until the duplicate is gone.
            while (windowSet.count(s[right]) > 0) {
                // Remove the character at the 'left' pointer from the set
                windowSet.erase(s[left]);
                // Move the left pointer forward to shrink the window
                left++;
            }
            
            // Now it's safe to add our new character to the set
            windowSet.insert(s[right]);
            
            // Calculate the current window size (right - left + 1)
            // and update maxLength if this window is the biggest one we've seen
            maxLength = max(maxLength, right - left + 1);
        } 
        
        return maxLength;
    }
};