class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nle(n, -1), ple(n, -1);
        for(int i=1; i<n; i++){
            ple[i] = max(ple[i-1], height[i-1]);
        }
        for(int i = n-2; i>=0; i--) {
            nle[i] = max(nle[i+1], height[i+1]);
        }
        int ans = 0;
        for(int i=1; i<n-1; i++){
            if(ple[i]==-1 || nle[i]==-1) continue;
            int h = min(nle[i], ple[i]);
            if(h>height[i]){
                int hn = h-height[i];
                ans+=(hn);
            }
        }
        return ans;
    }
};