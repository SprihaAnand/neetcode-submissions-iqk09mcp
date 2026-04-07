class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1) return n;

        int ans = 0;
        int l=0, r = 0;

        unordered_map<char, int> mpp;

        mpp[s[l]]=0;

        while(r<n-1 && l<=r){
            r++;
            while(l<=r && mpp.find(s[r])!=mpp.end() && mpp[s[r]]!=r){
                l=max(l,mpp[s[r]]+1);
                mpp[s[r]] =r;
            }
            mpp[s[r]]=r;
            ans = max(ans, (r-l+1));
        }
        return ans;
    }
};