/*
 * @lc app=leetcode.cn id=LCR 175 lang=cpp
 * @lcpr version=
 *
 * [LCR 175] 计算二叉树的深度
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int calculateDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int left_depth=calculateDepth(root->left);
        int right_depth=calculateDepth(root->right);
        return max(left_depth,right_depth)+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 2, 3, null, null, 5, 4, null, null, 4]\n
// @lcpr case=end

 */

