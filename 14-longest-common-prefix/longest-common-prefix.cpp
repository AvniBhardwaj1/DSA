class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Sort the array alphabetically
        sort(strs.begin(),strs.end());
        //first element and last element ko compare
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string s="";

        for(int i =0;i<first.size();i++){
            if(first[i]==last[i]){
                s+=first[i];// Append matching letters
            }else{
                break;
            }
        }
        return s;   
    }
};