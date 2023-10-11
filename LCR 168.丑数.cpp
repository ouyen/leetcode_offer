/*
 * @lc app=leetcode.cn id=LCR 168 lang=cpp
 * @lcpr version=
 *
 * [LCR 168] 丑数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        typedef vector<int>::iterator iter;
        iter multi2 = ugly.begin();
        iter multi3 = ugly.begin();
        iter multi5 = ugly.begin();
        for(int i = 1; i < n; i++){
            int min_ = min(min(*multi2 * 2, *multi3 * 3), *multi5 * 5);
            ugly[i] = min_;
            if(min_ == *multi2 * 2) ++multi2;
            if(min_ == *multi3 * 3) ++multi3;
            if(min_ == *multi5 * 5) ++multi5;
        }
        return ugly.back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

 */

