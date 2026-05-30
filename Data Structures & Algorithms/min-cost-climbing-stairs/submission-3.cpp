class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int nxt2 = 0;
        int nxt = 0;
        int curr;
        for(int i=n-1; i>=0; i--){
            curr = cost[i]+min(nxt, nxt2);
            nxt2 = nxt;
            nxt = curr;
        }
        return min(nxt2, nxt);
    }
};