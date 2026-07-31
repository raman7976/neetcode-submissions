class MinStack {
public:
    stack<int> st;
    stack<int> mono;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mono.empty() || mono.top()>=val)
        {
            mono.push(val);
        }

    }
    
    void pop() {
        if(st.empty())return ;

        if(st.top()==mono.top())
        {
            mono.pop();
        }
        st.pop();     
    }
    
    int top() {
        if(st.empty())return -1;
        return st.top();
    }
    
    int getMin() {
        return mono.top();
    }
};
