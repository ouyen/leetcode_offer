/*
 * @lc app=leetcode.cn id=剑指 Offer 31 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 31] 栈的压入、弹出序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> main_stack;
        auto pushed_index=pushed.begin();
        auto popped_index=popped.begin();

        while(pushed_index<pushed.end() && popped_index<popped.end()){
            while (pushed_index<pushed.end() && *pushed_index!=*popped_index){
                /* code */
                main_stack.push(*pushed_index);
                ++pushed_index;
            }
            if(pushed_index==pushed.end()) return false;
            ++pushed_index;// match
            ++popped_index;
            while(!main_stack.empty() && popped_index<popped.end() && main_stack.top()==*popped_index){
                main_stack.pop();
                ++popped_index;
            }
        }
        if(main_stack.empty()&& pushed_index==pushed.end() && popped_index==popped.end())
            return true;
        return false;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n[4,5,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n[4,3,5,1,2]\n
// @lcpr case=end

 */

int main(){
    vector<int> v1={1,2,3,4,5},v2={4,5,3,2,1};
    cout<<Solution().validateStackSequences(v1,v2)<<endl;
}