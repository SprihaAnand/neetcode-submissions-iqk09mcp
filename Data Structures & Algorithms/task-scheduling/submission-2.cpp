class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freq;
        int sum=0;
        for(auto it: tasks){
            freq[it]++;
        }
        priority_queue<int> pq;
        for(auto it: freq){
            pq.push(it.second);
        }
        int maxi = pq.top();
        sum+=maxi;
        pq.pop();
        int idle = (maxi-1)*n;
        while(!pq.empty()){
            idle-=min(maxi-1, pq.top());
            sum+=pq.top();
            pq.pop();
        }
        if(idle<0) idle=0;
        return sum+idle;
    }
};
