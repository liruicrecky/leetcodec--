// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<array<int, 2>> f(n + 1);

        for (int i = 1; i <= n; i++) {
            if (i - 1 == 0) {
                f[i][0] = 0;
                f[i][1] = -prices[i - 1];
                continue;
            }
            if (i - 2 == 0) {
                f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
                f[i][1] = max(f[i - 1][1], -prices[i - 1]);
                continue;
            }
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
            f[i][1] = max(f[i - 1][1], f[i - 2][0] - prices[i - 1]);
        }

        return f[n][0];
    }
};
// @lc code=end
