/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int x) {
        //因为是c++ STL中的stack
        stk.push(x);
        min_stk.push(min(min_stk.top(), x));
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(stk);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

