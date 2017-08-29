class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        
        if (minst.empty() || x <= minst.top()) {
            minst.push(x);
        }
    }
    
    void pop() {
        if (st.top() == minst.top()) {
            minst.pop();
        }
        
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
    
private:
    stack<int> st, minst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
