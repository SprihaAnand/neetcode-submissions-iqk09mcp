class Solution {
public:
    int help(int l, int r, string s){
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
        }
        return (r-l-1);
    }
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0; i<n; i++){
            //even
            int even = help(i, i, s);
            //odd
            int odd = help(i, i+1, s);
            res+= (even/2)+(odd/2)+1;
        }
        return res;
    }
};