/*
 * @lc app=leetcode.cn id=剑指 Offer 33 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 33] 二叉搜索树的后序遍历序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder_helper(postorder, 0, postorder.size() - 1);
    }
    bool verifyPostorder_helper(vector<int>& postorder, int start, int end) {
        // if (start == end)
        //     return true;
        // if (start > end) {
        //     return true;
        // }
        if(start+1>=end){
            return true;
        }
        int root = postorder[end];
        int right_begin = start;
        for (; right_begin <= end - 1; ++right_begin) {
            if (postorder[right_begin] > root) {
                break;
            }
        }
        int right_end = right_begin;
        for (; right_end <= end - 1; ++right_end) {
            if (postorder[right_end] < root) {
                return false;
            }
        }
        return verifyPostorder_helper(postorder, start, right_begin - 1) &&
               verifyPostorder_helper(postorder, right_begin, end - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,6,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,6,5]\n
// @lcpr case=end

 */

int main() {
    vector<int> v = {1, 2, 5, 10, 6, 9, 4, 3};
    cout << Solution().verifyPostorder(v) << endl;
}
