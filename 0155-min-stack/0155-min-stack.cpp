class MinStack {
public:
    stack<int> minStack,stack;
    MinStack() {
        
    }
    
    void push(int value) {
        stack.push(value);
        if(minStack.empty() || minStack.top()>=value)
            minStack.push(value);
    }
    
    void pop() {
        int top=stack.top(); stack.pop();
        if(minStack.top()==top) minStack.pop();
    }
    
    int top() {
        return stack.empty()?-1:stack.top();
    }
    
    int getMin() {
        return minStack.empty()?-1:minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */