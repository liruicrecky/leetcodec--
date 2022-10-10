// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution {
  public:
    int closedIsland(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dire = {1, 0, -1, 0, 1};

        auto dfs = [&](auto &&self, int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m)
                return false;

            if (grid[x][y] == 1 || grid[x][y] == 2)
                return false;

            if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                return true;

            grid[x][y] = 2;
            bool res = false;
            for (int i = 0; i < 4; i++) {
                int xx = x + dire[i], yy = y + dire[i + 1];
                res |= self(self, xx, yy);
            }
            return res;
        };

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    cnt += dfs(dfs, i, j) ? 0 : 1;
            }
        }

        return cnt;
    }
};
// @lc code=end
