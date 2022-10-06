// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
  public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> f(n, vector<int>(m));

        f[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);
        for (int j = m - 2; j >= 0; j--)
            f[n - 1][j] = max(1, f[n - 1][j + 1] - dungeon[n - 1][j]);
        for (int i = n - 2; i >= 0; i--)
            f[i][m - 1] = max(1, f[i + 1][m - 1] - dungeon[i][m - 1]);

        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                f[i][j] = max(1, min(f[i + 1][j], f[i][j + 1]) - dungeon[i][j]);
            }
        }

        return f[0][0];
    }
};
// @lc code=end
