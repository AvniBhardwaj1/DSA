class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1; // Fixed: points to the last valid index
        
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            
            if (sum == target) {
                return {l + 1, r + 1}; // Two Sum II is 1-indexed
            }
            else if (sum > target) {
                r--; // Sum is too big, bring the right pointer down
            }
            else {
                l++; // Fixed: Sum is too small, move the left pointer up
            }
        }
        
        return {}; // Default return if no solution is found (though problem guarantees one)
    }
};