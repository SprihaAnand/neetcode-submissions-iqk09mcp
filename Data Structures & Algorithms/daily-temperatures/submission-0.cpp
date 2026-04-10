class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);
        //number and ind
        for(int i = 0; i<n; i++) {
            if(st.empty()){
                st.push(make_pair(t[i], i));
            }
            else{
                while(!st.empty() && st.top().first<t[i]){
                    ans[st.top().second] = i-st.top().second;
                    st.pop();
                }
            }
            st.push(make_pair(t[i], i));
        }
        return ans;
    }
};
