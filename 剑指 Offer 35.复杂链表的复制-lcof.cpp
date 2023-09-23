// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=剑指 Offer 35 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 35] 复杂链表的复制
 */
#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
   public:
    // vector<Node*> Node_plist = {};
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* curr_node = head;
        // Node* prev_node=head;
        // curr_node=curr_node->next;
        while (curr_node != nullptr) {
            // copy curr_node
            Node* curr_copy = new Node(curr_node->val);
            curr_copy->next = curr_node->next;
            curr_copy->random = curr_node->random;

            curr_node->next = curr_copy;
            curr_node = curr_copy->next;
            // Node_plist.push_back(curr_copy);
        }

        // split copy
        curr_node = head;
        Node* copy_head=head->next;

        while (curr_node) {
            if(curr_node->next->random)
                curr_node->next->random = curr_node->next->random->next;
            curr_node = curr_node->next->next;
        }

        // reduce orginal
        curr_node = head;
        Node* tmp=head->next;
        while(curr_node){
            tmp=curr_node->next;
            if(tmp){
                curr_node->next=tmp->next;
            }
            curr_node=tmp;
        }
        return copy_head;
    }

    // ~Solution(){
    //     for(auto node:Node_plist){
    //         delete node;
    //     }
    // }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=Solution
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

int main(){
    // vector<Node*> Node_plist = {};
    Node* head=new Node(7);
    Node* node1=new Node(13);
    Node* node2=new Node(11);
    Node* node3=new Node(10);
    Node* node4=new Node(1);
    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node1->random=head;
    node2->random=node4;
    node3->random=node2;
    node4->random=head;
    Solution sol;
    Node* copy_head=sol.copyRandomList(head);
    while(copy_head){
        cout<<copy_head->val<<" "<<copy_head->random<<endl;
        copy_head=copy_head->next;
    }

    // delete
    delete head;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}