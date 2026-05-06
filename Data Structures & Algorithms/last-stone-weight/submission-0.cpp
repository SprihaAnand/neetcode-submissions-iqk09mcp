class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it: stones){
            pq.push(it);
        }
        while(pq.size()>1){
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();
            int curr = abs(one-two);
            if(curr) pq.push(curr);
        }
        if(!pq.size()) return 0;
        return pq.top();
    }
};
