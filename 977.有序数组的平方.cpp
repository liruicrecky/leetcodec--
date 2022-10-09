// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n);

        int l = 0, r = n - 1, idx = n - 1;
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                res[idx--] = nums[l] * nums[l];
                ++l;
            } else {
                res[idx--] = nums[r] * nums[r];
                --r;
            }
        }

        return res;
    }
};
// @lc code=end
