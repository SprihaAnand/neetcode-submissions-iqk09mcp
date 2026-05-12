class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freqmap;
        int sz = tasks.size();
        for(auto it: tasks){
            freqmap[it]++;
        }
        int max_freq = INT_MIN, cnt_max = 0;
        for(auto it: freqmap){
            max_freq = max(max_freq, it.second);
        }
        for(auto it: freqmap){
            if(it.second==max_freq) cnt_max++;
        }
        int total = (cnt_max)+ (n+1)*(max_freq-1);
        return max(sz, total);
    }
};
