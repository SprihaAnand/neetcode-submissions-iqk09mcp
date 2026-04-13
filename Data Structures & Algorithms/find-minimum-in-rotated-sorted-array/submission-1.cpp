class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int ans = INT_MAX;
        if(l==h) return nums[l];
        if(nums[l]<nums[h]) return nums[l];
        while(l<=h) {
            int mid = (h+l)/2;
            ans = min(ans, nums[mid]);
            if(nums[h]>=nums[l]){
                ans = min(ans, nums[l]);
                return ans;
            }
            else if(nums[mid]>=nums[l]){
                //mid is currently in left sorted portion
                l = mid+1;
            }
            else{
                h = mid-1;
            }            
        }
        return ans;
    }
};