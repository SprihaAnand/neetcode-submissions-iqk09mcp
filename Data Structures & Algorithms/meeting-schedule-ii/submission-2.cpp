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
        vector<int> back;
        for(auto it: i){
            bool done = false;

            for (auto& roomEnd : back) {
                if (roomEnd <= it.start) {
                    roomEnd = it.end;
                    done = true;
                    break;
                }
            }

            if (!done) {
                back.push_back(it.end);
            }
        }
        return back.size();
    }
};
