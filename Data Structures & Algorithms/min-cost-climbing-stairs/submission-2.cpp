class Solution {
public:
    // help(ind) = min(help(ind+1), help(ind+2))
    int help(vector<int>& cost, vector<int>& dp, int ind){
        if(ind >= cost.size()) {
            //base  
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = cost[ind]+
                        min(
                        help(cost, dp, ind+1),
                        help(cost,dp, ind+2)
                    );
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(help(cost, dp, 0), help(cost, dp, 1));
    }
};