class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(!nums.size()) return ans;
        ans.push_back({});
        for(int i = 0; i<nums.size(); i++){
            auto it = nums[i];
            int sz = ans.size();
            for(int i=0; i<sz; i++){
                vector<int> h = ans[i];
                h.push_back(it);
                ans.push_back(h);
            }
        }
        return ans;
    }
};