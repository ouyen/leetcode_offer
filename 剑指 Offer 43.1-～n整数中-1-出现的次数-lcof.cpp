/*
 * @lc app=leetcode.cn id=剑指 Offer 43 lang=cpp
 * @lcpr version=
 *
 * [剑指 Offer 43] 1～n 整数中 1 出现的次数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int digitOneInNumber(int num) {
        long digit = 1;
        int high = num / 10, cur = num % 10, low = 0, res = 0;
        while(high != 0 || cur != 0) {
            if(cur == 0) res += high * digit;
            else if(cur == 1) res += high * digit + low + 1;
            else res += (high + 1) * digit;
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */

int main(){
    Solution sol;
    // int num;
    vector<int> nums{0,13};
    for(auto& num:nums){
        cout<<sol.digitOneInNumber(num)<<endl;
    }
    return 0;
}