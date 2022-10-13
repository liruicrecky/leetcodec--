// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<array<int, 2>>> f(n + 1, vector<array<int, 2>>(3));
        
        for (int i = 1; i <= n; i++) {
            for (int k = 2; k > 0; k--) {
                if (i - 1 == 0) {
                    f[i][k][0] = 0;
                    f[i][k][i] = -prices[i - 1];
                    continue;
                }
                f[i][k][0] =
                    max(f[i - 1][k][0], f[i - 1][k][1] + prices[i - 1]);
                f[i][k][1] =
                    max(f[i - 1][k][1], f[i - 1][k - 1][0] - prices[i - 1]);
            }
        }

        return f[n][2][0];
    }
};
// @lc code=end
