/*
 * @lc app=leetcode.cn id=剑指 Offer 32 - II lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 32 - II] 从上到下打印二叉树 II
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        array<queue<TreeNode*>,2> q;
        int q_select=0;
        vector<vector<int>> result;
        if(root==nullptr) return result;
        q[q_select].push(root);
        result.push_back({});
        while(!q[0].empty() || !q[1].empty()){
            TreeNode* top=q[q_select].front();
            q[q_select].pop();
            result.back().push_back(top->val);
            // result.push_back(top->val);
            if(top->left) q[!q_select].push(top->left);
            if(top->right) q[!q_select].push(top->right);
            if(q[q_select].empty()&&!q[!q_select].empty()){
                result.push_back({});
                q_select=!q_select;
            }
        }
        return result;

    }
};
// @lc code=end

int main(){
    vector<int> tree_int={3,9,20,-1,-1,15,7};
    vector<TreeNode*> tree;
    tree.resize(tree_int.size());
    int i=0;
    for(i=0;i<tree.size();++i){
        if(tree_int[i]!=-1)
            tree[i]=new TreeNode(tree_int[i]);
        else
            tree[i]=nullptr;
    }
    int n=tree.size();
    for(i=0;i<n/2;++i){
        if(tree[i]){
            if(2*i+1<n) tree[i]->left=tree[2*i+1];
            if(2*i+2<n) tree[i]->right=tree[2*i+2];
        }
    }
    for(auto& v:Solution().levelOrder(tree[0])){
        for(auto& vv:v){
            cout<<vv<<" ";
        }
        cout<<endl;
    }
    // cout<<endl;
    for(i=0;i<tree.size();++i){
        delete tree[i];
    }
}

