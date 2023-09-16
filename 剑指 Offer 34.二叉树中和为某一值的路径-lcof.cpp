/*
 * @lc app=leetcode.cn id=剑指 Offer 34 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 34] 二叉树中和为某一值的路径
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    int target_sum = 0;
    vector<vector<int>> path;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        target_sum = target;
        path.push_back({});
        if (root)
            dfs_search(root, 0);
        path.pop_back();
        return path;
    }
    void dfs_search(TreeNode* root, int curr_sum) {
        curr_sum += root->val;
        path.back().push_back(root->val);
        bool isLeaf = (root->left == nullptr) && (root->right == nullptr);
        if (curr_sum == target_sum && isLeaf) {
            // get a path
            path.push_back(path.back());
            path.back().pop_back();
            return;
        }
        if (root->left)
            dfs_search(root->left, curr_sum);
        if (root->right)
            dfs_search(root->right, curr_sum);
        // if(!path.back().empty())
        path.back().pop_back();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */

int main() {
    vector<int> tree_int = {1, 2};
    int sum = 1;
    vector<TreeNode*> tree;
    tree.resize(tree_int.size());
    int i = 0;
    for (i = 0; i < tree.size(); ++i) {
        if (tree_int[i] != -1)
            tree[i] = new TreeNode(tree_int[i]);
        else
            tree[i] = nullptr;
    }
    int n = tree.size();
    for (i = 0; i < n / 2; ++i) {
        if (tree[i]) {
            if (2 * i + 1 < n)
                tree[i]->left = tree[2 * i + 1];
            if (2 * i + 2 < n)
                tree[i]->right = tree[2 * i + 2];
        }
    }
    for (auto& v : Solution().pathSum(tree[0], sum)) {
        for (auto& vv : v) {
            cout << vv << " ";
        }
        cout << endl;
    }
    // cout << endl;
    for (i = 0; i < tree.size(); ++i) {
        delete tree[i];
    }
}
