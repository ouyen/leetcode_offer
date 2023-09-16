
/*
 * @lc app=leetcode.cn id=剑指 Offer 30 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 30] 包含min函数的栈
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> main_stack={};
    vector<int> min_stack={};
    MinStack() {

    }
    
    void push(int x) {
        main_stack.push_back(x);
        if (min_stack.empty()) {
            min_stack.push_back(x);
        }
        else{
            min_stack.push_back(std::min(x,min_stack.back()));
        }
    }
    
    void pop() {
        main_stack.pop_back();
        min_stack.pop_back();
    }
    
    int top() {
        return main_stack.back();
    }
    
    int min() {
        return min_stack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
// @lc code=end



