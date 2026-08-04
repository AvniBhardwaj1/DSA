#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each number using a hash map
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        
        // Step 2: Use a min-heap to keep track of the top k elements
        // The heap stores pairs of {frequency, element}
        // Greater means it's a min-heap based on frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for (auto& entry : countMap) {
            int num = entry.first;
            int freq = entry.second;
            
            minHeap.push({freq, num});
            
            // If the heap size exceeds k, remove the element with the smallest frequency
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Step 3: Extract the elements from the min-heap into the result vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};