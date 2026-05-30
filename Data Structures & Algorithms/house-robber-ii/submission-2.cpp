class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+2);
        vector<int> dp2(n+2);
        dp[n+1] = dp[n] = 0;
        dp2[n+1] = dp2[n] = 0;
        for(int i = n-2; i>=0; i--){
            dp[i]= max(dp[i+1], nums[i]+dp[i+2]);
        }
        for(int i = n-1; i>=1; i--){
            dp2[i]= max(dp2[i+1], nums[i]+dp2[i+2]);
        }
        return max(dp[0],dp2[1]);
    }
};

