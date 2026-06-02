class Solution {
public:
    int isPalin(int l, int r, string s, vector<vector<int>>& dp){
        int n = s.size();
        if(l>=r) return true;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r]=isPalin(l+1, r-1, s, dp);
        }
        else return dp[l][r]=false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int i=0; i<n; i++){
            for(int j = i; j<n; j++){
                if(isPalin(i, j, s, dp)) res++;
            }
        }
        return res;
    }
};