class MinStack {
public:
    stack<long long> st;
    long long curr_min = 0;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            curr_min = val;
        }
        else {
            st.push((long long)val - curr_min);
            if(val < curr_min) curr_min = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long v = st.top();
        st.pop();
        if(v < 0) {
            curr_min -= v;
        }
    }
    
    int top() {
        return st.top() > 0 ? (int)(st.top() + curr_min) : (int)curr_min;
    }
    
    int getMin() {
        return (int)curr_min;
    }
};