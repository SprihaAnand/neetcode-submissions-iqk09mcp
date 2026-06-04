class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX));
        for(int i=0; i<n; i++){
            dp[i][0]=0;
        }
        for(int i=n-1; i>=0; i--){
            for(int amt = 1; amt<=amount; amt++){
                int take = INT_MAX;
                if(amt-coins[i]>=0)
                take = dp[i][amt-coins[i]];
                if(take!=INT_MAX) take = 1+take;
                dp[i][amt] = min(take,dp[i+1][amt]);
            }
        }
        return dp[0][amount]==INT_MAX?-1:dp[0][amount];
    }
};