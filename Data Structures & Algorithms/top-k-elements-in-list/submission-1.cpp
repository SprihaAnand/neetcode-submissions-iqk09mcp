class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        for(auto it:mpp){
            int freq = it.second;
            int num = it.first;
            buckets[freq].push_back(num);
        }
        vector<int> ans;
        for(int i=n; i>=0; i--){
            if(buckets[i].size()>0){
                for(auto d: buckets[i]){
                    ans.push_back(d);
                    if(ans.size()==k) return ans;
                }
            }
        }
        return ans;
    }
};