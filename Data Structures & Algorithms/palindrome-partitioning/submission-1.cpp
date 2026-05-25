class Solution {
public:
    bool isPalindrome(string& str, int l, int r, vector<vector<int>>& dp) {
        if(dp[l][r]!=-1) return dp[l][r];
        while (l < r) {
            if (str[l] != str[r]) return dp[l][r] = 0;
            l++;
            r--;
        }
        return dp[l][r] = 1;
    }
    void help(vector<vector<string>>& ans, string& s, int ind, vector<string>& temp, vector<vector<int>>& dp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i, dp)){
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
        vector<vector<int>> dp(n, vector<int>(n, -1));
        help(ans, s, 0, temp, dp);
        return ans;
    }
};