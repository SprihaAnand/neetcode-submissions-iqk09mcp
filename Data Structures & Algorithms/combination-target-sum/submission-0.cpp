class Solution {
public:
    void help(vector<int>& c, int t, vector<vector<int>>& ans, int ind, vector<int> temp){
        if(ind==c.size() || t<0) {
            if(t==0)
                ans.push_back(temp);
            return;
        }
        help(c,t,ans,ind+1,temp);
        temp.push_back(c[ind]);
        help(c,t-c[ind], ans, ind, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(c, t, ans, 0, temp);
        return ans;
    }
};