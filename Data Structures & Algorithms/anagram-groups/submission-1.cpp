class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mpp;
        //frequency signature -> list of the strings
        for(auto it: strs){
            //build frequency signature
            vector<int> v(26,0);
            for(auto ch: it){
                v[ch-'a']++;
            }
            string freqSign = to_string(v[0]);
            for(int i=1; i<26; i++){
                freqSign+= (',')+ to_string(v[i]);
            }
            mpp[freqSign].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};