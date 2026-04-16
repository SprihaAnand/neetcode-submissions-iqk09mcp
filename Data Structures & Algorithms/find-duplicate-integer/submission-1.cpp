class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = nums[0];
        int sv;
        while(nums[i] !=-1){
            sv = nums[i];
            nums[i]=-1;
            i = sv;
        }
        return sv;
    }
};