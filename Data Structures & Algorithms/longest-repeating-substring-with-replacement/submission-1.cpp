class Solution {
public:
    int characterReplacement(string s, int k) {
        //window is valid as long as
        //window size – count of the most frequent character ≤ k
        unordered_map<char, int> cnt;
        int st = 0, end = 0;
        int n = s.size();
        int currmax = 0, ans = 0;
        while(st<=end && end<n){
            cnt[s[end]]++;
            currmax = max(currmax, cnt[s[end]]);
            while((end-st+1)-currmax>k){
                cnt[s[st]]--;
                st++;
            }
            ans = max(ans, end-st+1);
            end++;
        }
        return ans;
    }
};