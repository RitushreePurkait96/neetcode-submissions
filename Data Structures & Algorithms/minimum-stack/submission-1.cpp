class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    int minVal = INT_MIN;
    MinStack() {  
    }
    
    void push(int val) {
        if(minst.empty())
            minst.push(val);
        else
        {
            if(val <= minst.top())
            {
                minst.push(val);
            }
        }
        st.push(val);
    }
    
    void pop() {
        if(st.empty() || minst.empty())
            return;
        if(st.top() == minst.top())
        {
            minst.pop();
        }
        st.pop();    
    }
    
    int top() {
        if(st.empty())
            return -1;
        return st.top();    
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return minst.top();    
    }
};
