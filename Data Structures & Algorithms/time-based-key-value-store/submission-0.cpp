class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        auto &f = mp[key];
        // vector<int> ts;
        // for(auto it: f){
        //     ts.push_back(it.second);
        // }
        //finding the index,if not found then lower bound
        int l = 0, r = f.size()-1;
        int ansInd = -1;
        while(l<=r){
            int mid = (r-l)/2+l;
           
            if(f[mid].second<=timestamp) {
                ansInd = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        if(ansInd==-1) return "";
        return f[ansInd].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */