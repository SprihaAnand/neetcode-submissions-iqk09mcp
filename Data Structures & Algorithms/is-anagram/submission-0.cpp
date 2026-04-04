class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char, int> mpp;
        for(auto ch: s){
            mpp[ch]++;
        }
        for(auto it: t){
            if(mpp[it]) mpp[it]--;
            else return false;
        }
        return true;
    }
};
