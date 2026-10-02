class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    
    MinStack() {
        // Constructor doesn't need to do anything special here
    }
    
    void push(int val) {
        st.push(val);
        // Fix 1 & 3: Check if minst is empty, and use <= to handle duplicate minimums
        if (minst.empty() || val <= minst.top()) {
            minst.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        // If the element we are removing is the current minimum, pop it from minst too
        if (st.top() == minst.top()) {
            minst.pop();
        }
        st.pop();    
    }
    
    int top() {
        if (st.empty()) return -1;
        return st.top();    
    }
    
    int getMin() {
        if (minst.empty()) return -1;
        return minst.top();    
    }
};