// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
  public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size();

        // 0 positive 1 negative
        vector<array<int, 2>> f(n + 1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (nums[i - 1] - nums[j - 1] > 0)
                    f[i][0] = max(f[i][0], f[j][1] + 1);
                else if (nums[i - 1] - nums[j - 1] < 0)
                    f[i][1] = max(f[i][1], f[j][0] + 1);
            }
        }

        return max(f[n][0], f[n][1]) + 1;
    }
};
// @lc code=end
