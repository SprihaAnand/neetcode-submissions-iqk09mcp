class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int tot_product = 1, e=1;
        int nonz = 0;
        for(auto it: nums){
            tot_product*=it;
            if(it) e*=it;
            if(it==0) nonz++;
        }
        vector<int> n(nums.size(), 0);
        if(nonz>1) return n;
        for(auto it: nums){
            if(it!=0)
                ans.push_back(tot_product/it);
            else {
                ans.push_back(e);
            }
        }
        return ans;
    }
};