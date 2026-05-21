class Solution {
public:
    void help(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, int ind){
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }
        //not taking at all
        int nu = ind;
        while(nu<nums.size() && nums[nu]==nums[ind]){
            nu++;
        }   
        help(nums, ans, temp, nu);
        temp.push_back(nums[ind]);
        help(nums, ans, temp, ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        help(nums, ans, temp, 0);
        return ans;
    }
};