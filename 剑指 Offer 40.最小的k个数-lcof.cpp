/*
 * @lc app=leetcode.cn id=剑指 Offer 40 lang=cpp
 * @lcpr version=
 *
 * [剑指 Offer 40] 最小的k个数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        multiset<int,greater<int>> leastNums={};
        if(cnt<1 || cnt>stock.size()){
            return vector<int>{};
        }

        auto iter=stock.begin();
        for(;iter!=stock.end();++iter){
            if(leastNums.size()<cnt){
                leastNums.insert(*iter);
            }
            else{
                auto iter_greatest=leastNums.begin();
                if(*iter<*iter_greatest){
                    leastNums.erase(iter_greatest);
                    leastNums.insert(*iter);
                }
            }
        }
        vector<int> result;
        for(auto&i:leastNums){
            result.push_back(i);
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,7,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,2,3,6]\n2\n
// @lcpr case=end

 */

int main(){
    vector<int> stock{10,9,8,7,6,5,4,3,2,1,0};
    for(auto&i:Solution().inventoryManagement(stock,5)){
        cout<<i<<" ";
    }
    cout<<endl;
}