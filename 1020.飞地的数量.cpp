// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
  public:
    int numEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int dire[] = {0, 1, 0, -1, 0};

        auto dfs = [&](auto &&self, int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m)
                return;
            if (grid[x][y] == 0)
                return;

            grid[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                int xx = x + dire[i], yy = y + dire[i + 1];
                self(self, xx, yy);
            }
        };

        // rows and cols
        for (int i = 0; i < n; i++) {
            dfs(dfs, i, 0);
            dfs(dfs, i, m - 1);
        }

        for (int j = 1; j < m - 1; j++) {
            dfs(dfs, 0, j);
            dfs(dfs, n - 1, j);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    ++res;
            }
        }

        return res;
    }
};
// @lc code=end
