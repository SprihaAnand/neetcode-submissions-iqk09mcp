class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mpp;
        // freq, the number
        for(int i = 0; i< nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while(!pq.empty() && k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};