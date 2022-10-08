// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
  public:
    int numTrees(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1));

        auto count = [&](auto &&self, int l, int r) {
            if (l > r)
                return 1;

            if (memo[l][r] != 0)
                return memo[l][r];

            int res = 0;
            for (int mid = l; mid <= r; ++mid) {
                int left = self(self, l, mid - 1);
                int right = self(self, mid + 1, r);
                res += left * right;
            }

            return memo[l][r] = res;
        };

        return count(count, 1, n);
    }
};
// @lc code=end
