class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return n;
        int ans = 1;
        unordered_set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        int maxi = 1;
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                //starts from this
                int len = 1;
                while(st.find(it+1)!=st.end()){
                    len++;
                    maxi = max(len, maxi);
                    it++;
                }
            }
        }
        return maxi;
    }
};