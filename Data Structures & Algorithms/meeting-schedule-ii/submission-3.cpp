/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& i) {
        sort(i.begin(), i.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it: i){
            if(pq.size() && pq.top()>it.start) pq.push(it.end);
            else{
                if(pq.size())
                pq.pop();
                pq.push(it.end);
            }
        }
        return pq.size();
    }
};
