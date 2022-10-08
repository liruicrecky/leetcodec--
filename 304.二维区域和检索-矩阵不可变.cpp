// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
  private:
    vector<vector<int>> sumM;

  public:
    NumMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if (n == 0 || m == 0)
            return;

        sumM.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sumM[i][j] = sumM[i - 1][j] + sumM[i][j - 1] +
                             matrix[i - 1][j - 1] - sumM[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumM[row2 + 1][col2 + 1] - sumM[row1][col2 + 1] -
               sumM[row2 + 1][col1] + sumM[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
