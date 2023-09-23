/*
 * @lc app=leetcode.cn id=剑指 Offer 36 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 36] 二叉搜索树与双向链表
 */
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public: 
    vector<Node*> tree_list={};
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr) return nullptr;
        inorder_traversal(root);
        tree_list.front() -> left  = nullptr;
        tree_list.back()  -> right = nullptr;
        for(int i = 1; i < tree_list.size() -1; ++i){
            tree_list[i] -> left  = tree_list[i-1];
            tree_list[i] -> right = tree_list[i+1];
        }
        return tree_list.front();
    }   
    void inorder_traversal(Node* root){
        if(root == nullptr) return;
        if(root -> left){
            inorder_traversal(root->left);
        }      
        tree_list.push_back(root);
        if(root -> right){
            inorder_traversal(root->right);
        }      
    }   
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,5,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

