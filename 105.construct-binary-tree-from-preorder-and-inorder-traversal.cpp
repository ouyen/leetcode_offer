/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=21913
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    vector<int> _preorder;
    vector<int> _inorder;
    // TreeNode _tree[100];
    // int _tree_i=0;
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
        // _tree[_tree_i]=TreeNode(root_val);
        // TreeNode* root = &_tree[_tree_i];
        // ++_tree_i;
        TreeNode* root = new TreeNode(root_val);
        // auto root = make_unique<TreeNode>(root_val);
        auto root_index_iter = find(_inorder.begin()+inorder_start,_inorder.begin()+inorder_end,root_val);
        int root_index = root_index_iter - _inorder.begin();
        int left_tree_size = root_index - inorder_start;
        root->left = buildTree_helper(preother_start+1,preother_start+left_tree_size,inorder_start,root_index-1);
        root->right = buildTree_helper(preother_start+left_tree_size+1,preother_end,root_index+1,inorder_end);
        return root;
    }
    vector<TreeNode*> make_heap(TreeNode* root){
        vector<TreeNode*> res;
        // int depth=1;
        int start=0;
        int end=0;
        int temp=0;
        bool end_flag=false;
        res.push_back(root);
        vector<TreeNode*> res_tmp;
        int i=0;
        while(!end_flag){
            end_flag=true;
            for(i=start;i<=end;++i){
                if(res[i]!=NULL){
                    res_tmp.push_back(res[i]->left);
                    res_tmp.push_back(res[i]->right);
                    // end_flag=false;
                    if((res[i]->left!=NULL)||res[i]->right!=NULL){
                        end_flag=false;
                    }
                }
                else{
                    res_tmp.push_back(NULL);
                    res_tmp.push_back(NULL);
                }
            }
            if(!end_flag){
                res.insert(res.end(),res_tmp.begin(),res_tmp.end());
                res_tmp.clear();
            }
            start=start*2+1;
            end=start*2;
        }
        // depth=
        return res;
    }
    void print_heap(vector<TreeNode*> heap){
        int i=0;
        for(i=0;i<(heap.size());++i){
            if(heap[i]==NULL){
                cout<<"null ";
            }
            else{
                cout<<heap[i]->val<<" ";
            }
        }
        cout<<endl;
    }
    void print_tree(TreeNode* root){
        int x=1;
        print_heap(make_heap(root));
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

void test(){
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    auto t=s.buildTree(preorder,inorder);
    s.print_tree(t);
    
}
void test_print(){
    Solution s;
    TreeNode t3(3);
    TreeNode t9(9);
    TreeNode t20(20);
    TreeNode t15(15);
    TreeNode t7(7);
    t3.left=&t9;
    t3.right=&t20;
    t20.left=&t15;
    t20.right=&t7;
    s.print_tree(&t3);
    
}

int main(){
    test();
    // test_print();
    return 0;
}