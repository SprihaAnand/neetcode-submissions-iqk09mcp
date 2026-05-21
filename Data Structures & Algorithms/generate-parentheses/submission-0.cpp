class Solution {
public:
    void help(vector<string>& ans, int n, int open, int closing, string temp){
        if(open+closing == 2*n){
            ans.push_back(temp);
            return;
        }
        if(open>closing){
            help(ans, n, open, closing+1, temp+")");
        }
        if(open<n)
            help(ans, n, open+1, closing, temp+"(");
    }
    vector<string> generateParenthesis(int n) {
        //a closing bracket can come only if no of open>no of closed
        //and at the end no of open==no of closed
        vector<string> ans;
        string temp = "";
        help(ans, n, 0, 0, temp);
        return ans;
    }
};