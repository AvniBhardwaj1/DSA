class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // ans is size of nums.size() and initialize every element to 1
        vector<int> ans(nums.size(),1);
        //[1,1,1,1]
        int prefix=1;
        int suffix=1;
        //Pass 1: Compute prefix products (all from left)
        for (int i=0;i<nums.size();i++){
            ans[i]=prefix;
            //update prefix value
            prefix=prefix*nums[i];
        }
        // 2. Pass 2: Compute suffix products (products of all elements to the right) and multiply
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= suffix;
            //update prefix value
            suffix *= nums[i];
        }
        
        return ans;
        
    }
};