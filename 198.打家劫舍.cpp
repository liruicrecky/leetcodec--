// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        f[1] = nums[0];
        
        for (int i = 2; i <= n; i++) {
            f[i] = max(f[i - 1], nums[i - 1] + f[i - 2]);
        }

        return f[n];
    }
};
// @lc code=end

