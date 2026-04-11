class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int, int>> vp;
        int n = p.size();
        for(int i = 0; i<n; i++){
            vp.push_back(make_pair(p[i], s[i]));
        }
        vector<double> st;
        sort(vp.rbegin(), vp.rend());
        for(auto it: vp){
            double time = (double)(target-it.first)/it.second;
            st.push_back(time);
            if(st.size()>=2 && st[st.size()-2]>=st.back()){
                st.pop_back();
            }
        }
        return st.size();
    }
};