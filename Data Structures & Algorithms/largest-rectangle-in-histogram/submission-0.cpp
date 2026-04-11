class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> pse(n, -1), nse(n, n);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        int ans = INT_MIN;
        for(int i = 0; i<n; i++) {
            ans = max(ans , (nse[i]-pse[i]-1)*h[i]);
        }
        return ans;
    }
};