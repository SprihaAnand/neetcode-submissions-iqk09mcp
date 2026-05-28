class Solution {
public:
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void help(string digits, vector<string>& ans, int ind, string temp){
        if(temp.size()==digits.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<mp[digits[ind]-'0'].size(); i++){
            char ch = mp[digits[ind]-'0'][i];
            temp = temp+ch;
            help(digits, ans, ind+1,temp);
            temp.pop_back();
        }       
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> ans;
        string temp = "";
        help(digits, ans, 0, temp);
        return ans;
    }
};