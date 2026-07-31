// Logic (Current Approach - String):
// 1. Convert the integer to a string.
// 2. Use two pointers: one from the left, one from the right.
// 3. Compare the characters at both pointers.
// 4. If any pair doesn't match, return false.
// 5. If all pairs match until the pointers meet, return true.

// Better Interview Approach (Without String):
// 1. Negative numbers are never palindromes.
// 2. Reverse only HALF of the number using % and /.
// 3. Compare the first half with the reversed second half.
// 4. If they are equal (or equal after removing the middle digit), it's a palindrome.
// 5. Uses O(1) extra space instead of converting to a string.
class Solution {
public:
    bool isPalindrome(int x) {

        string s = to_string(x);

        int l = 0;
        int r = s.size() - 1;

        while (l < r) {

            if (s[l] != s[r]) {
                return false;
            }

            l++;
            r--;

        }

        return true;
    }
};