/*
 * @lc app=leetcode.cn id=剑指 Offer 09 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 09] 用两个栈实现队列
 */
using namespace std;
#include<bits/stdc++.h>
// @lc code=start
class CQueue {
    stack<int> _in;
    stack<int> _out;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        _in.push(value);
    }
    
    int deleteHead() {
        if(_out.empty()){
            if(_in.empty()){
                return -1;
            }
            while(!_in.empty()){
                _out.push(_in.top());
                _in.pop();
            }
        }
        int res = _out.top();
        _out.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
// @lc code=end



/*
// @lcpr case=start
// ["CQueue","appendTail","deleteHead","deleteHead","deleteHead"][[],[3],[],[],[]]\n
// @lcpr case=end

// @lcpr case=start
// ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"][[],[],[5],[2],[],[]]\n
// @lcpr case=end

 */

int main(){
    CQueue obj = CQueue();
    obj.appendTail(1);
    obj.appendTail(2);
    obj.appendTail(3);

    cout<<obj.deleteHead()<<endl;
    cout<<obj.deleteHead()<<endl;
    cout<<obj.deleteHead()<<endl;
    return 0;
}

