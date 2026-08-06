class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // points to the position where a non-zero should go
        
        for (int i = 0; i < nums.size(); i++) {
            // When we encounter a non-zero, we swap it into our target position 'j'
            // (which naturally pushes zeros back)
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};