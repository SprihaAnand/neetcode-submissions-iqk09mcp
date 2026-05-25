class Solution {
public:
    void help(vector<vector<string>>& ans, string& s, int ind, vector<string>& temp, vector<vector<int>>& dp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i<s.size(); i++){
            if(dp[ind][i]){
                temp.push_back(s.substr(ind, i - ind + 1));
                help(ans, s, i+1, temp, dp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int l=0; l<n; l++){
            for(int r = l; r<n; r++){
                int i=l, j=r;
                bool ok = true;
                while (i < j) {
                    if (s[i] != s[j]) {
                        ok = false;
                        break;
                    }
                    i++;
                    j--;
                }
                dp[l][r] = ok;
            }
        }
        help(ans, s, 0, temp, dp);
        return ans;
    }
};