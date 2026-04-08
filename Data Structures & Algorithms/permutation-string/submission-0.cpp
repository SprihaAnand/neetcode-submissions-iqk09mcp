class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // so window size will be s2.size
        int l=0, r=0;
        int n=s1.size(), m=s2.size();
        map<char, int> mpp1, mpp2;
        for(auto it: s1){
            mpp1[it]++;
        }
        while(r<m && l<=r){
            mpp2[s2[r]]++;
            while(r-l+1>n){
                mpp2[s2[l]]--;
                if(mpp2[s2[l]] == 0) mpp2.erase(s2[l]);
                l++;
            }
            if(mpp1==mpp2) return true;
            r++;
        }
        return false;
    }
};