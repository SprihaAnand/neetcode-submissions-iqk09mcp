class Solution {
public:

    vector<int> sizes;

    string encode(vector<string>& strs) {
        if(strs.size()==0) return "";
        string ans = "";
        for(auto it: strs){
            sizes.push_back(it.size());
            ans+=it;
        }
        return ans;
    }

    vector<string> decode(string s) {
        if(sizes.size()==0) return {};
        string ans = "";
        vector<string> ansvector;
        int curr = 0;
        for(auto it: sizes){
            while(it--){
                ans+=s[curr];
                curr++;
            }
            ansvector.push_back(ans);
            ans="";
        }
        return ansvector;
    }
};
