class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int ans = INT_MAX;
        if(l==h) return nums[l];
        while(l<h) {
            int mid = (h+l)/2;
            if(nums[mid]>nums[mid+1]){
                //rotated found the pivot
                return nums[mid+1];
            }
            else if(nums[l]<nums[h]){
                //sorted
                ans = min(ans, nums[l]);
                return ans;
            }
            else if(nums[mid]>nums[l]){
                //rotated didnt find the pivot
                ans = min(ans, nums[l]);
                l = mid+1;
            } 
            else if(nums[mid]<nums[h]){
                ans = min(ans, nums[mid]);
                h = mid-1;
            }
        }
        return ans;
    }
};