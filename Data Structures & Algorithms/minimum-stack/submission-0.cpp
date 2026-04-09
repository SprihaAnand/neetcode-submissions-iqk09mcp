class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mini = min(mini, val);
        st.push(val);
        min_st.push(mini);
    }
    
    void pop() {
        if(st.empty()) return;
        else{
            st.pop();
            min_st.pop();
            if(!min_st.empty()) mini = min_st.top();
            else mini = INT_MAX;
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */