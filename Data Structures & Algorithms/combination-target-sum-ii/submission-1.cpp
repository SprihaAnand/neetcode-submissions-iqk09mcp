class Solution {
public:
    void help(vector<int>& c, int t, vector<vector<int>>& ans, vector<int>& temp, int ind){
        if(t==0) {
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<c.size(); i++){
            if(i>ind && c[i]==c[i-1]){
                continue;
            }
            if(c[i]>t) break;
            temp.push_back(c[i]);
            help(c, t-c[i], ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<int> temp;
        vector<vector<int>> ans;
        help(c, t, ans, temp, 0);
        return ans;
    }
};