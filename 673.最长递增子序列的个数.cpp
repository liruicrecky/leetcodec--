// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
  public:
    int findNumberOfLIS(vector<int> &nums) {
        int ans = 0, maxLen = 1, n = nums.size();
        vector<int> f(n + 1, 1), counts(n + 1, 1);

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (nums[i - 1] > nums[j - 1]) {
                    if (f[j] + 1 > f[i]) {
                        f[i] = f[j] + 1;
                        counts[i] = counts[j];
                    } else if (f[j] + 1 == f[i])
                        counts[i] += counts[j];
                }
                maxLen = max(maxLen, f[i]);
            }
        }

        for (int i = 1; i <= n; i++)
            if (f[i] == maxLen)
                ans += counts[i];

        return ans;
    }
};
// @lc code=end
