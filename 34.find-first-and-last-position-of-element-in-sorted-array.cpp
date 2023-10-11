/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    enum SearchType {
        FIRST,
        LAST,
    };
    int BinarySearch(vector<int>&nums,int target,int left,int right,Solution::SearchType type){
        if(left>right){
            return -1;
        }
        int middle=(left+right)/2;
        if(nums[middle]==target){
            if(type==Solution::SearchType::FIRST){
                if(middle==0||nums[middle-1]!=target){
                    return middle;
                }else{
                    return BinarySearch(nums,target,left,middle-1,type);
                }
            }else{
                if(middle==nums.size()-1||nums[middle+1]!=target){
                    return middle;
                }else{
                    return BinarySearch(nums,target,middle+1,right,type);
                }
            }
        }else if(nums[middle]>target){
            return BinarySearch(nums,target,left,middle-1,type);
        }else{
            return BinarySearch(nums,target,middle+1,right,type);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {BinarySearch(nums,target,0,nums.size()-1,Solution::SearchType::FIRST),BinarySearch(nums,target,0,nums.size()-1,Solution::SearchType::LAST)};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

int main(){
    Solution sol;
    vector<int> nums={5,7,7,8,8,10};
    int target=6;
    auto ans=sol.searchRange(nums,target);
    cout<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}