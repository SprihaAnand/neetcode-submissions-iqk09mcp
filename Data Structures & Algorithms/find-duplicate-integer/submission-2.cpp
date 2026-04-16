class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        fast = nums[nums[fast]];
        slow = nums[slow];
        while(fast!=slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        int slow2 = 0;
        while(slow!=slow2){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow2;
    }
};