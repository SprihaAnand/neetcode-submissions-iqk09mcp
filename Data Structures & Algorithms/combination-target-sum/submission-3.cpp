class Solution {
public:
    void help(vector<int>& c, int t, vector<vector<int>>& ans, int ind, vector<int>& temp){
        if(t==0)
        {
            ans.push_back(temp);
            return;
        }
        if(ind==c.size() || t<0 || c[ind]>t) {
            return;
        }
        temp.push_back(c[ind]);
        help(c,t-c[ind], ans, ind, temp);
        temp.pop_back();
        help(c,t,ans,ind+1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<vector<int>> ans;
        vector<int> temp;
        help(c, t, ans, 0, temp);
        return ans;
    }
};