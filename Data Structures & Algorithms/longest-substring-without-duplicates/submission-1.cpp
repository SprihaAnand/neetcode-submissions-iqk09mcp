class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1) return n;

        int ans = 0;
        int l=0, r = 0;

        unordered_set<char> st;

        st.insert(s[l]);

        while(r<n-1 && l<=r){
            r++;
            while(l<=r && st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans = max(ans, (r-l+1));
        }
        return ans;
    }
};