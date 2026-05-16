class Solution {
public:
    void help(vector<int>& nums, vector<vector<int>>& ans, int ind, vector<int> temp){
        if(ind==nums.size()) {
            ans.push_back(temp);
            return;
        }
        help(nums, ans, ind+1, temp);
        temp.push_back(nums[ind]);
        help(nums, ans, ind+1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        help(nums, ans,0, tmp);
        return ans;
    }
};