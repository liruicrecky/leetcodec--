// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int sell = 0, hold = INT_MIN;
        for (const auto &price : prices) {
            sell = max(sell, hold + price);
            hold = max(hold, -price);
        }

        return sell;
    }
};
// @lc code=end
