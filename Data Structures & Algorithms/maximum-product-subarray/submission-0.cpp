class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int p = 1;
            for(int j=i; j<n; j++){
                p*=nums[j];
                maxi = max(maxi, p);
            }
        }
        return maxi;
    }
};