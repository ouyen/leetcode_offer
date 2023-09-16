/*
 * @lc app=leetcode.cn id=剑指 Offer 06 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 06] 从尾到头打印链表
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start

//  * Definition for singly-linked list.
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode(int x) : val(x), next(NULL) {}
//  };

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head){
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n
// @lcpr case=end

 */

