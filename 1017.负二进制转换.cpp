// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */

// @lc code=start
class Solution {
  public:
    string baseNeg2(int n) {
        if (n == 0)
            return "0";

        string ans;
        while (n) {
            int m = n & 1;
            ans += to_string(m);
            n = (n - m) / -2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end
