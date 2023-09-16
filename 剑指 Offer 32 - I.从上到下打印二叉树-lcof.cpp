/*
@lc app=leetcode.cn id=剑指 Offer 32 - I lang=cpp
@lcpr version=21913
 *
[剑指 Offer 32 - I] 从上到下打印二叉树
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// /**
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//  */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q={};
        vector<int> result={};
        if(root==nullptr) return result;
        q.push(root);
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            result.push_back(top->val);
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        return result;

    }
};
// @lc code=end




//PASS!
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
        cout<<v<<" ";
    }
    cout<<endl;
    for(i=0;i<tree.size();++i){
        delete tree[i];
    }
}