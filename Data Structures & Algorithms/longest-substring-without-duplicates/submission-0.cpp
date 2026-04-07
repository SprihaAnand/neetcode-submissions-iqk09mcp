class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1) return n;

        int ans = 0;
        int l=0, r = 0;

        unordered_map<char, int> mpp;

        mpp[s[l]]++;

        while(r<n-1 && l<=r){
            r++;
            mpp[s[r]]++;
            while(l<=r && mpp[s[r]]>1){
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans, (r-l+1));
        }
        return ans;
    }
};