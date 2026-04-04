class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];
            int f = target- curr;
            if(mpp[f]) return {mpp[f]-1, i};
            mpp[curr] = i+1;
        }
        return {-1, -1};
    }
};
