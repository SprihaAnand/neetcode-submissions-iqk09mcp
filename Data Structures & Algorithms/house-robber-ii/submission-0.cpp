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
        if(n==1) return nums[0];
        vector<int> nums2 = nums;
        nums.pop_back();
        nums2.erase(nums2.begin());
        vector<int> dp(n, -1);
        vector<int> dp2(n, -1);
        return max(help(0, nums,dp), help(0,nums2, dp2));
    }
};

