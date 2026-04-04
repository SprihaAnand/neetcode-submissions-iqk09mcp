class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n, 1), suffixSum(n,1);
        vector<int> ans(n,1);

        for(int i = 1; i<n; i++){
            preSum[i] = preSum[i-1]* nums[i-1];
        }

        for(int i = n-2; i>=0; i--){
            suffixSum[i] = suffixSum[i+1]*nums[i+1];
        }
        for(int i= 0; i<n; i++){
            ans[i] = preSum[i]*suffixSum[i];
        }
        return ans;
    }
};