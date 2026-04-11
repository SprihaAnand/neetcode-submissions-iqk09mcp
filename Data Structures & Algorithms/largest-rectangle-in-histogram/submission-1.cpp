class Solution {
public:
    int largestRectangleArea(vector<int>& h) {

        vector<int> st;
        int ans = INT_MIN;
        int n = h.size();
        for(int i = 0; i<n; i++) {
            while(!st.empty() && h[st[st.size()-1]]>h[i]){
                if(st.size()>1) {
                    ans = max(ans, (i-st[st.size()-2]-1) * h[st[st.size()-1]]);
                }
                else ans = max(ans, (i)*h[st[st.size()-1]]);
                st.pop_back();
            }
            st.push_back(i);
        }
        while(!st.empty()) {
            int top = st.back();
            st.pop_back();

            if(st.empty())
                ans = max(ans, n * h[top]);
            else
                ans = max(ans, (n - st.back() - 1) * h[top]);
        }
        return ans;
    }
};