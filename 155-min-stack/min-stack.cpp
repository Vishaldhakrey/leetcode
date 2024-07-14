#include <stack>
#include <climits>

class MinStack {
public:
    std::stack<long long> st;
    long long minVal;

    MinStack() {
        while (!st.empty()) st.pop();
        minVal = LLONG_MAX;
    }
    
    void push(int val) {
        long long value = val;
        if (st.empty()) {
            st.push(value);
            minVal = value;
        } else {
            if (value < minVal) {
                // Push a special value and update minVal
                st.push(2 * value - minVal);
                minVal = value;
            } else {
                st.push(value);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        long long ele = st.top();
        st.pop();

        // If the popped element is less than minVal, it means it's a special value
        if (ele < minVal) {
            minVal = 2 * minVal - ele;
        }
    }
    
    int top() {
        long long item = st.top();

        // If the top element is a special value, the actual top is minVal
        if (item < minVal) return minVal;
        
        return item;
    }
    
    int getMin() {
        return minVal;
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
