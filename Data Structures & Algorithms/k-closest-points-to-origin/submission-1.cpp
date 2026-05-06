class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        for(auto it: points){
            int x = it[0];
            int y = it[1];
            double dist = sqrt(x*x+y*y);
            pq.push(make_pair(dist, make_pair(x,y)));
        }
        vector<vector<int>> ans;
        while(ans.size()<k){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};