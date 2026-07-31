// Pehle sort kardo , then index wise check -> n log n + n^2 = O(N^2) gave time limite exceed
//instead use Hashset (unordered_list)
//class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for (int i=0 ; i<nums.size();i++){
//             for (int j=i+1; j<nums.size();j++){
//                 if (nums[i]==nums[j]){
//                     return true;
//                 }

//             }
//         }
//         return false;
        
//     }
// };
class Solution {
    public:
    bool containsDuplicate(vector<int> & nums){
        unordered_set<int> seen;
        for (int x: nums){
            if (seen.count(x)){
                return true;
            }
            seen.insert(x);

        }
        return false;

    }
};
// 1. Create an unordered_set to store numbers we've already seen.
// 2. Traverse the array one element at a time.
// 3. If the current number is already in the set, a duplicate exists → return true.
// 4. Otherwise, insert the current number into the set.
// 5. If the loop finishes without finding a duplicate, return false.

// Pattern: HashSet (unordered_set)
// Time: O(n) average
// Space: O(n)

// Create
// unordered_set<int> s;

// Insert
// s.insert(10);

// Check if element exists (returns 1 if found, 0 otherwise)
// s.count(10);

// Better way to check
// if (s.count(10)) {
//     // Found
// }

// Remove an element
// s.erase(10);

// Number of elements
// s.size();

// Check if empty
// s.empty();

// Remove all elements
// s.clear();

// Traverse all elements
// for (int x : s) {
//     cout << x << " ";
// }

// Find (returns iterator)
// if (s.find(10) != s.end()) {
    // Found
//}

// Does NOT exist
// if (s.find(10) == s.end()) {
    // Not Found
//}