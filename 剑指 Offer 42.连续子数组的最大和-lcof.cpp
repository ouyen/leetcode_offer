/*
 * @lc app=leetcode.cn id=剑指 Offer 42 lang=cpp
 * @lcpr version=
 *
 * [剑指 Offer 42] 连续子数组的最大和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int maxSales(vector<int>& sales) {
        // vector<int> dp(sales.size(),0);
        int dp = 0;
        dp = sales[0];
        int max_dp = dp;
        for (int i = 1; i < sales.size(); ++i) {
            dp = max(dp, 0) + sales[i];
            max_dp = max(max_dp, dp);
        }
        return max_dp;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
int main() {
    // vector<int> sales = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> sales = {5, 4, -1, 7, 8};
    cout << Solution().maxSales(sales) << endl;
}
