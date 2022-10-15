// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1)
            return false;

        int tar = sum >> 1;

        int n = nums.size();
        vector<bool> f(tar + 1, false);
        f[0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = tar; j >= nums[i]; j--) {
                f[j] = f[j] || f[j - nums[i]];
            }
        }

        return f[tar];
    }
};
// @lc code=end
