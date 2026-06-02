class Solution {
public:
    int helpo(int i, string s){
        int n = s.size();
        int left = i-1, right=i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return (right-left-1);
    }
    int helpe(int i, string s){
        int left = i, right=i+1;
        int n = s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return (right-left-1);
    }
    string longestPalindrome(string s) {
        int start;
        int n = s.size();
        int res = -1, resLen = 0;
        for(int i=0; i<n; i++){
            int even = helpe(i, s);
            int odd = helpo(i, s);
            if(resLen<max(even, odd)){
                resLen = max(even, odd);
                res = i;
                if(odd>even){
                    start = i-(resLen/2);
                }else{
                    start = i-((resLen/2)-1);
                }
            }
        } 
        return s.substr(start, resLen);
    }
};