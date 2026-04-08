class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(char ch = 'A'; ch<='Z'; ch++){
            if(s.find(ch)==string::npos) continue;
            //checking for every letter
            int st = 0;
            int end =0;
            int currDiff = 0;
            while(st<=end && end<n){
                if(s[end]!=ch){
                    currDiff++;
                }
                while(st<=end && currDiff>k){
                    if(s[st]!=ch) currDiff--;
                    st++;
                }
                ans = max(ans, end-st+1);
                end++;
            }
        }
        return ans;
    }
};