class Solution {
public:
    int help(int ind, vector<int>& nums, vector<int>& dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]= max(help(ind+1, nums, dp), nums[ind]+help(ind+2, nums, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return help(0, nums,dp);
    }
};