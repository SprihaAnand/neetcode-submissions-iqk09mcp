class KthLargest {
public:
    priority_queue<int> pq; int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k-1;
        for(auto it:nums){
            pq.push(it);
        }
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> save = pq;
        int k = kth;
        while(k--){
            save.pop();
        }
        return save.top();
    }
};
