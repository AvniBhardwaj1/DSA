class Solution {
public:
    void sortColors(vector<int>& nums) {
        //low , mid and high 3 pointers rhenge
        //mid is our deciding factor
        //if it gets 0 -> swaps with low  and increments low++ and mid++; 
        //1-> keeps with itself and. moves on ; 
        //2 mila-> swaps with high and high ptr--
        // main conditon is while (mid<=high)

        int low=0;
        int mid=0;
        int high= nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                //swap kardo low se
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                //jab mid ko 2 mila
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};