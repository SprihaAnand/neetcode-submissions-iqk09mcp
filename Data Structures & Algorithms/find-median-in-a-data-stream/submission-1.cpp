class MedianFinder {
public:
    // left  = max heap for smaller half
    // right = min heap for larger half
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.size()>maxHeap.size()){
            minHeap.push(num);
            int mini = minHeap.top();
            minHeap.pop();
            maxHeap.push(mini);
            //minHeap bigger
        }
        else{
            maxHeap.push(num);
            int maxi = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxi);
        }
    }
    
    double findMedian() {
        int sz1 = minHeap.size();
        int sz2 = maxHeap.size();
        int tot = sz1+sz2;
        if(tot%2==0){
            int mini = minHeap.top();
            int maxi = maxHeap.top();
            return (double)(mini+maxi)/2.0;
        } else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */