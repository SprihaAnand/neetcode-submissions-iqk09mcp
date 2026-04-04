class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size()==0) return "";
        string ans = "";
        for(auto it: strs) {
            ans+=("  %"+it);
        }
        return ans;
    }

    vector<string> decode(string s) {
        if(s.size()==0) return {};
        vector<string> ans;
        string curr = "";
        for(int i=3; i<s.size(); i++){
            if(s[i]==' ' && s[i+1]==' ' && s[i+2]=='%') {
                ans.push_back(curr);
                curr="";
                i+=2;
            }
            else{
                curr+=s[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};
