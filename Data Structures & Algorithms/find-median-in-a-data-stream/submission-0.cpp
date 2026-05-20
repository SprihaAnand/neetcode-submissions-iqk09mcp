class MedianFinder {
public:
    priority_queue<int> pq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        priority_queue<int> temp = pq;
        int sz = temp.size();
        int half = sz/2;
        if(sz%2){
            // odd size
            while(half>0){
                half--;
                temp.pop();
            }
            return temp.top();
        } else{
            // 1 2 3 4 half = 2
            while(half>1){
                half--;
                temp.pop();
            }
            int one = temp.top();
            temp.pop();
            int two = temp.top();
            return (double)((one+two)/2.0);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */