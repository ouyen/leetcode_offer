/*
 * @lc app=leetcode.cn id=剑指 Offer 45 lang=cpp
 * @lcpr version=
 *
 * [剑指 Offer 45] 把数组排成最小的数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    class cmp{
        public:
        bool operator()(const int& a,const int& b){
            string sa = to_string(a);
            string sb = to_string(b);
            return sa+sb < sb+sa;
        }
    };
public:
    string crackPassword(vector<int>& password) {
        sort(password.begin(),password.end(),cmp());
        string res;
        for(auto& num:password){
            res.append(to_string(num));
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [15, 8, 7]\n
// @lcpr case=end

// @lcpr case=start
// [0, 3, 30, 34, 5, 9]\n
// @lcpr case=end

 */

int main(){
    Solution sol;
    vector<int> password = {15, 8, 7};
    cout << sol.crackPassword(password) << endl;
    password = {0, 3, 30, 34, 5, 9};
    cout << sol.crackPassword(password) << endl;
    return 0;
}
