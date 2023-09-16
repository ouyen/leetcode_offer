/*
//@lc app=leetcode.cn id=剑指 Offer 07 lang=cpp
//@lcpr version=21913
 *
//[剑指 Offer 07] 重建二叉树
 */
using namespace std;
#include<bits/stdc++.h>
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
//Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
 */
class Solution {
    vector<int> _preorder;
    vector<int> _inorder;
    vector<TreeNode> _tree;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        _preorder = preorder;
        _inorder = inorder;
        return buildTree_helper(0, preorder.size()-1, 0, inorder.size()-1);

    }
    TreeNode* buildTree_helper(int preother_start,int preother_end,int inorder_start,int inorder_end){
        if(preother_start>preother_end){
            return NULL;
        }
        if(inorder_start>inorder_end){
            return NULL;
        }

        int root_val = _preorder[preother_start];
        _tree.push_back(TreeNode(root_val));
        TreeNode* root = &_tree[_tree.size()-1];
        auto root_index_iter = find(_inorder.begin()+inorder_start,_inorder.begin()+inorder_end,root_val);
        int root_index = root_index_iter - _inorder.begin();
        int left_tree_size = root_index - inorder_start;
        root->left = buildTree_helper(preother_start+1,preother_start+left_tree_size,inorder_start,root_index-1);
        root->right = buildTree_helper(preother_start+left_tree_size+1,preother_end,root_index+1,inorder_end);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

