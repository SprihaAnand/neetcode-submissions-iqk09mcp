class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for(auto it: tasks){
            mpp[it]++;
        }
        priority_queue<int> pq;
        //storing remaininf frequencies in inc order
        for(auto it: mpp){
            pq.push(it.second);
        }
        int curr_time = 0;
        queue<pair<int, int>> cool_down;
        //stores task those need to cool down (available at, freq)
        while(!pq.empty() || !cool_down.empty()){
            curr_time++;
            if(!pq.empty()){
                int curr_freq = pq.top();
                pq.pop();
                if(curr_freq-1){
                    cool_down.push(make_pair(curr_time+n, curr_freq-1));
                }
            }
            if(!cool_down.empty() && cool_down.front().first==curr_time){
                pq.push(cool_down.front().second);
                cool_down.pop();
            }
        }
        return curr_time;
    }
};