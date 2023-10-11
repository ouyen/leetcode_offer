/*
 * @lc app=leetcode.cn id=LCR 170 lang=cpp
 * @lcpr version=
 *
 * [LCR 170] 交易逆序对的总数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    vector<int> tmp;

   public:
    int reversePairs(vector<int>& record) {
        tmp.resize(record.size());
        return MergeSort(record, 0, record.size() - 1);
    }
    int MergeSort(vector<int>& record, int l, int r) {
        if (l >= r)
            return 0;
        int mid = (l + r) >> 1;
        int res = MergeSort(record, l, mid) + MergeSort(record, mid + 1, r);
        int i = l, j = mid + 1;

        vector<int>::iterator tmp_it = tmp.begin();
        while (i <= mid && j <= r) {
            if (record[i] <= record[j]) {
                *tmp_it = record[i];
                ++tmp_it;
                ++i;
            } else {
                *tmp_it = record[j];
                ++tmp_it;
                res += mid - i + 1;
                ++j;
            }
        }
        for (; i <= mid; ++i) {
            *tmp_it = record[i];
            ++tmp_it;
        }
        // for (; j <= r; ++j) {
        //     *tmp_it = record[j];
        //     ++tmp_it;
        // }
        copy(tmp.begin(), tmp.begin() + (j - l), record.begin() + l);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [9, 7, 5, 4, 6]\n
// @lcpr case=end

 */

int main() {
    vector<int> record{9, 7, 5, 4, 6};
    Solution sol;
    cout << sol.reversePairs(record) << endl;
    for (auto& i : record) {
        cout << i << " ";
    }
    cout << endl;
}
