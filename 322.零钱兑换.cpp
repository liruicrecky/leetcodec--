// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> f(amount + 1, INT_MAX);
        f[0] = 0;

        for (const auto &coin : coins) {
            for (int i = 1; i <= amount; i++) {
                if (i >= coin && f[i - coin] != INT_MAX)
                    f[i] = min(f[i], f[i - coin] + 1);
            }
        }

        return f[amount] == INT_MAX ? -1 : f[amount];
    }
};
// @lc code=end
