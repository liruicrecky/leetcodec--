// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();

        int sum = 0, minSum = 0;
        int str = 0;

        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            if (sum < minSum) {
                str = i + 1;
                minSum = sum;
            }
        }

        if (sum < 0)
            return -1;

        return str == n ? 0 : str;
    }
};
// @lc code=end
