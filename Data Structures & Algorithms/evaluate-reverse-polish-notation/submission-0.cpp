class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens){
            if(it=="+" || it== "-" || it=="*" || it=="/"){
                int f = st.top();
                st.pop();
                int s = st.top();
                st.pop();
                if(it=="+") st.push(f+s);
                else if(it=="-") st.push(s-f);
                else if(it=="*") st.push(f*s);
                else st.push(s/f);
            }
            else st.push(stoi(it));
        }
        return st.top();
    }
};
