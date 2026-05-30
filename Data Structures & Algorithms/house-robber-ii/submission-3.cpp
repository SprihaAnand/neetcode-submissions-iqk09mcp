class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int p1=0,p2=0;
        int r1=0, r2=0;
        int c1,c2;
        for(int i = n-2; i>=0; i--){
            c1= max(p1, nums[i]+p2);
            p2=p1;
            p1=c1;
        }
        for(int i = n-1; i>=1; i--){
            c2= max(r1, nums[i]+r2);
            r2=r1;
            r1=c2;
        }
        return max(p1,r1);
    }
};

