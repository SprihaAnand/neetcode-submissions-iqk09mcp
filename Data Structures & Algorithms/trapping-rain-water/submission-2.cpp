class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if(n==0 || n==1) return 0;
        int left = 0,
        right = n-1,
        leftMax = h[left],
        rightMax = h[right],
        ans = 0;
        while(left<right){
            if(h[left]>h[right]){
                int wtr=min(leftMax, rightMax)-h[right];
                if(wtr>0) ans+=wtr;
                right--;
                rightMax = max(rightMax, h[right]);
            }
            else{
                int wtr = min(leftMax, rightMax)-h[left];
                if(wtr>0) ans+=wtr;
                left++;
                leftMax = max(leftMax, h[left]);
            }
        }
        return ans;
    }
};