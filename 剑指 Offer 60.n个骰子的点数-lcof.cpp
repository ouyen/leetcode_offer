/*
 * @lc app=leetcode.cn id=剑指 Offer 60 lang=cpp
 * @lcpr version=21917
 *
 * [剑指 Offer 60] n个骰子的点数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<double> statisticsProbability(int num) {
        int n=num;
        vector<double> dp(6, 1.0 / 6.0);
        for (int i = 2; i <= n; i++) {
            vector<double> tmp(5 * i + 1, 0);
            for (int j = 0; j < dp.size(); j++) {
                for (int k = 0; k < 6; k++) {
                    tmp[j + k] += dp[j] / 6.0;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

int main(){
    cout<<"[";
    for(auto& i:Solution().statisticsProbability(200)){
        cout<<i<<", ";
    }
    cout<<"]"<<endl;
}

