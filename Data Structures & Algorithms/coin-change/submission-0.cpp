class Solution {
public:
    void help(vector<int>& coins, int amt, int count, int& mini, int ind){
        if(ind==coins.size() || amt<=0){
            //all done
            if(amt==0)
            mini = min(mini, count);
            return;
        }
        help(coins, amt-coins[ind], count+1, mini, ind);
        help(coins, amt, count, mini, ind+1);

    }
    int coinChange(vector<int>& coins, int amount) {
        int mini = INT_MAX;
        help(coins, amount, 0, mini,0);
        return mini==INT_MAX?-1:mini;
    }
};