// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
  public:
    void solve(vector<vector<char>> &board) {
        int n = board.size(), m = board[0].size();
        int dire[] = {1, 0, -1, 0, 1};

        auto dfs = [&](auto &&self, int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m)
                return;
            if (board[x][y] == 'X' || board[x][y] == 'P')
                return;
            board[x][y] = 'P';
            for (int i = 0; i < 4; i++) {
                int xx = x + dire[i], yy = y + dire[i + 1];
                self(self, xx, yy);
            }
        };

        for (int i = 0; i < n; i++) {
            dfs(dfs, i, 0);
            dfs(dfs, i, m - 1);
        }

        for (int j = 1; j < m - 1; j++) {
            dfs(dfs, 0, j);
            dfs(dfs, n - 1, j);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'P')
                    board[i][j] = 'O';
            }
        }
    }
};
// @lc code=end
