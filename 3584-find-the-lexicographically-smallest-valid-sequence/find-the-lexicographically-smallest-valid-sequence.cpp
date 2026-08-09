#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // matchRight[i] stores the farthest index in word2 that can be matched 
        // using the suffix of word1 starting at index i
        vector<int> matchRight(n + 1, m);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            matchRight[i] = j + 1; // First index of word2 that needs matching from index i onwards
        }
        
        vector<int> ans;
        bool usedChange = false;
        j = 0; // Tracks current index in word2 we are trying to match
        
        for (int i = 0; i < n; ++i) {
            if (j < m && word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!usedChange && j < m && matchRight[i + 1] <= j + 1) {
                // Use our one allowed change here
                ans.push_back(i);
                usedChange = true;
                j++;
            }
            
            if (j == m) {
                return ans;
            }
        }
        
        return {};
    }
};