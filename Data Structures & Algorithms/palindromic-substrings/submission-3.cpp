class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=0; i<n; i++){
            int j=0;
            while(j<=i){
                dp[i][j]=1;
                j++;
            }
        }
        
        for(int l=n; l>=0; l--){
            for(int r=l+1; r<n; r++){
                if(s[l]==s[r]){
                    dp[l][r]=dp[l+1][r-1];
                }
                else dp[l][r]=0;
                }
        }
        for(int i=0; i<n; i++){
            for(int j = i; j<n; j++){
                if(dp[i][j]) res++;
            }
        }
        return res;
    }
};