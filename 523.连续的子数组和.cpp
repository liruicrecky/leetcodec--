// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            preSum[i] = preSum[i - 1] + nums[i - 1];

        unordered_set<int> set;
        for (int i = 2; i <= n; i++) {
            set.insert(preSum[i - 2] % k);
            if (set.count(preSum[i] % k))
                return true;
        }

        return false;
    }
};
// @lc code=end
