class Solution {
public:
    int help(string s, int ind, vector<int>& dp){
        if(ind==s.size()){
            return 1;
        }
        if(dp[ind]!=-1) return dp[ind];
        //single digit
        if(s[ind]=='0') return dp[ind]=0;
        int ways = help(s, ind+1, dp);
        if(ind+1<s.size())
        //only if <26
        {
            int num = (s[ind]-'0')*10+(s[ind+1]-'0');
            if(num<=26)
            ways+=help(s, ind+2, dp);
        }
        return dp[ind]=ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return help(s, 0, dp);
    }
};