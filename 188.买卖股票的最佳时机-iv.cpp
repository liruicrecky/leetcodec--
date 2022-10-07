// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<array<int, 2>>> f(n + 1, vector<array<int, 2>>(k + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = k; j > 0; j--) {
                if (i - 1 == 0) {
                    f[i][j][0] = 0;
                    f[i][j][1] = -prices[i - 1];
                    continue;
                }
                f[i][j][0] =
                    max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
                f[i][j][1] =
                    max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
            }
        }

        return f[n][k][0];
    }
};
// @lc code=end
