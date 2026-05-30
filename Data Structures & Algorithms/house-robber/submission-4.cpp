class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, -1);
        int next1 = 0;
        int next2=0;
        int curr;
        for(int i=n-1; i>=0; i--){
            curr= max(next1, nums[i]+next2);
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
};