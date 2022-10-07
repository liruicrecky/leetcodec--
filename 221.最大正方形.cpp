// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

        int maxLen = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '0')
                    f[i][j] = 0;
                else
                    f[i][j] =
                        min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
                maxLen = max(maxLen, f[i][j]);
            }
        }

        return maxLen * maxLen;
    }
};
// @lc code=end
