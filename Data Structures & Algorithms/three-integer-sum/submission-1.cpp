class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(i>0 && nums[i-1]==nums[i]) continue;

            int st = i+1, end = n-1;
            int target = -nums[i];

            while(st<end)
            {
                int curr = nums[st]+nums[end];
                if(curr>target){
                    end--;
                }
                else if(curr<target){
                    st++;
                }
                else {
                    ans.push_back({nums[i], nums[st], nums[end]});
                    st++;
                    end--;
                    while(st<end && nums[st]==nums[st-1]) st++;
                    while(st<end && nums[end+1]==nums[end]) end--;
                }
            }
        }
        return ans;
    }
};
