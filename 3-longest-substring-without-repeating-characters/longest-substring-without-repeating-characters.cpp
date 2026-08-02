/*
// YOUR ORIGINAL SOLUTION:
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> mymap;
// 
//         for(int i =0;i< s.size();i++){
//             if(mymap.count(s[i])==0){
//                 mymap.insert(s[i]);
//             }
// 
//         } 
//         return mymap.size();
//     }
// };

// WHY IT WAS WRONG:
// 1. It counts the total number of unique characters in the entire string, not a contiguous substring.
// 2. If given "pwwkew", your code returns 4 ('p', 'w', 'k', 'e'). The actual longest substring is "wke" (3).
// 3. It never resets or shrinks when it encounters a duplicate character.

// THE CORRECT IDEA (SLIDING WINDOW):
// - Use two pointers ('left' and 'right') to create a "window" of characters.
// - Expand the window to the right by adding characters to a set.
// - If you hit a duplicate at the 'right' pointer, shrink the window from the 'left' 
//   by removing characters from the set until that duplicate is gone.
// - Update the maximum length recorded each time you successfully add a new character.
*/

#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            while (window.count(s[right]) > 0) {
                window.erase(s[left]);
                left++;
            }
            
            window.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        } 
        
        return maxLength;
    }
};