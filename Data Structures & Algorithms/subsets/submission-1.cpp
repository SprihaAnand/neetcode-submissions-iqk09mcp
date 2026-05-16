class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(!nums.size()) return ans;
        ans.push_back({});
        for(int i = 0; i<nums.size(); i++){
            auto it = nums[i];
            vector<vector<int>> help;
            for(auto res: ans){
                vector<int> h = res;
                h.push_back(it);
                help.push_back(h);
            }
            for(auto i:help){
                ans.push_back(i);
            }
        }
        return ans;
    }
};