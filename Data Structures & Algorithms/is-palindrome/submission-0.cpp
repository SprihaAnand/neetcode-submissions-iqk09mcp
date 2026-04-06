class Solution {
public:
    bool isPalindrome(string s) {
        string st = "";
        for(auto it:s){
            if((it>='a'&& it<='z') || (it>='A'&& it<='Z') || (it>='0')&& (it<='9')){
                st+=tolower(it);
            }
        }
        int i = 0;
        int j = st.size()-1;
        while(i<=j){
            if(st[i]!=st[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};