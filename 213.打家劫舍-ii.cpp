// @before-stub-for-debug-begin
#include <cstddef>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
  private:
    void help(vector<int> &f, vector<int> &nums, int s, int e) {
        f[s] = nums[s];
        f[s + 1] = max(nums[s], nums[s + 1]);
        for (int i = s + 2; i <= e; i++)
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
    }

  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> f(n), g(n);
        help(f, nums, 0, n - 2);
        help(g, nums, 1, n - 1);

        return max(f[n - 2], g[n - 1]);
    }
};
// @lc code=end
