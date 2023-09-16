/*
 * @lc app=leetcode.cn id=剑指 Offer 04 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 04] 二维数组中的查找
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = 0;
        while(row >= 0 && col < matrix[0].size()){
            if(matrix[row][col] > target) row--;
            else if(matrix[row][col] < target) col++;
            else return true;
        }
        return false;
    }
};
// @lc code=end



