class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<map<char, int>, int> record;
        int curr=1;
        for(auto it: strs) {
            map<char, int> mpp;
            for(auto ch: it) {
                mpp[ch]++;
            }
            if(record[mpp]) {
                ans[record[mpp]-1].push_back(it);
            }
            else {
                record[mpp] = curr;
                curr++;
                ans.push_back({it});
            }           
        }
        return ans;
    }
};