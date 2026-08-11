#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int i = 0;
        
        // Step 1: Find the longest sequential prefix sum
        while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
            sum += nums[i + 1];
            i++;
        }
        
        // Step 2: Store all elements in an unordered_set for O(1) lookups
        unordered_set<int> present(nums.begin(), nums.end());
        
        // Step 3: Find the smallest integer >= sum that is missing from the set
        int x = sum;
        while (present.count(x)) {
            x++;
        }
        
        return x;
    }
};