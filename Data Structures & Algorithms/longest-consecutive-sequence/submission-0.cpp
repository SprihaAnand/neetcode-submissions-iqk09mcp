class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        //[0,3,7,2,5,8,4,6,0,1]
        //[0,0,1,2,3,4,5,6,7,8]
        //0,1,1,2
        int maxi = INT_MIN;
        int n = nums.size();
        if(n==0 || n==1) return n;
        for(int i =1 ; i<n; i++) {
            if(nums[i]-1==nums[i-1]){
                ans++;
                maxi = max(maxi, ans);
            }
            else if(nums[i]!=nums[i-1]){
                ans = 1;
            }
        }
        return maxi==INT_MIN?1:maxi;
    }
};