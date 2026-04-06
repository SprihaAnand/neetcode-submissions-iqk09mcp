class Solution {
public:
    bool isPalindrome(string st) {
        int i = 0;
        int n = st.size();
        int j = n-1;
        if(n==0 || n==1) return true;
        while(i<=j){
            while(i<n && !isalnum(st[i])){
                i++;
            }
            while(j>0 && !isalnum(st[j])){
                j--;
            }
            if(i<=j && tolower(st[i])!=tolower(st[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};