class Solution {
public:
    int help(vector<int>& coins, int amt, vector<vector<int>>& dp, int ind){
        if(ind==coins.size() || amt<=0){
            //all done
            if(amt==0)
            return 0;
            else
            return INT_MAX;         
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int take = help(coins, amt-coins[ind], dp, ind);
        if(take!=INT_MAX) take = 1+take;
        return dp[ind][amt] = min(take,help(coins, amt, dp, ind+1));

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = help(coins, amount,dp, 0);
        return ans==INT_MAX?-1:ans;
    }
};