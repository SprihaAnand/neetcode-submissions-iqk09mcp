class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
     
        for(int i = 0; i<n; i++){
            pq.push({nums[i], i});
            while(pq.top().second<=i-k){
                pq.pop();
            }
            if(pq.size()>=k) ans.push_back(pq.top().first);
        }
        return ans;
    }
};