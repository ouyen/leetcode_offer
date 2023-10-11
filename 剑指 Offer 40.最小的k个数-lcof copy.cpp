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
// based on quick-sort-like partitiaon
    int Part(vector<int>& stock,int start,int end){
        int key=stock[end-1];
        int i=start;
        for(int j=start;j<end-1;++j){
            if(stock[j]<key){
                swap(stock[i],stock[j]);
                ++i;
            }
        }
        swap(stock[i],stock[end-1]);
        return i;
    }
    int QuickFind(vector<int>&stock,int start,int end,int target){
        if(start>=end){
            throw "start>=end";
        }
        int p=Part(stock,start,end);

        if(p==target){
            return stock[p];
        }
        if(p>target){
            return QuickFind(stock,start,p,target);
        }
        else{
            return QuickFind(stock,p+1,end,target);
        }
    }
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        QuickFind(stock,0,stock.size(),cnt-1);
        return vector<int>(stock.begin(),stock.begin()+cnt);
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