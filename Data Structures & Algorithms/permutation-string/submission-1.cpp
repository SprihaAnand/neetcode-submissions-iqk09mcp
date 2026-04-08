class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s2.size(), n = s1.size();
        if(n>m) return false;
        vector<int> v1(26,0), v2(26,0);
        for(int i = 0; i<n; i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        int matches = 0;
        for(int i = 0; i<26; i++) {
            if(v1[i]==v2[i]) matches++;
        }
        for(int j = 0; j<m-n; j++) {
            if(matches==26) return true;
            int r = s2[j + s1.size()] - 'a';
            v2[r]++;
            if (v2[r] == v1[r]) matches++;
            else if (v2[r] == v1[r] + 1) matches--;
            int l = s2[j] - 'a';
            v2[l]--;
            if (v2[l] == v1[l]) matches++;
            else if (v2[l] == v1[l] - 1) matches--;
        }
        return matches==26;
    }
};