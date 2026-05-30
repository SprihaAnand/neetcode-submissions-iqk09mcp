class Solution {
public:
    int help(int ind, vector<int>& nums, vector<int>& dp, int n){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]= max(help(ind+1, nums, dp,n), nums[ind]+help(ind+2, nums, dp,n));
    }
   
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n, -1);
        vector<int> dp2(n, -1);
        return max(help(0, nums,dp,n-1), help(1,nums, dp2,n));
    }
};

