class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = (r-l)/2+l;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[l]){
                //left is sorted
                if(nums[mid]>=target && nums[l]<=target){
                    //between l and mid
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            else{
                //right is sorted
                if(nums[r]>=target && nums[mid]<=target){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};