class Solution {
public:
    int trap(vector<int>& h) {
        stack<int> st;
        int ans = 0;
        int n = h.size();
        if(n==0 || n==1) return 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && h[i]>=h[st.top()]){
                int curr = h[st.top()];
                st.pop();
                if(!st.empty()){
                    int w = i-st.top()-1;
                    ans+=(min(h[st.top()], h[i])-curr)*w;
                }
            }
            st.push(i);
        }
        return ans;
    }
};