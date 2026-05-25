class Solution {
public:
    bool isPalindrome(string& str, int l, int r) {
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void help(vector<vector<string>>& ans, string s, int ind, vector<string>& temp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                temp.push_back(s.substr(ind, i - ind + 1));
                help(ans, s, i+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        help(ans, s, 0, temp);
        return ans;
    }
};