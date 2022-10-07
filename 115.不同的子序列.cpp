// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
  public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        auto dfs = [&](auto &&self, int i, int j) {
            if (j == m)
                return 1;

            if (m - j > n - i)
                return 0;

            if (memo[i][j] != -1)
                return memo[i][j];

            int res = 0;
            if (s[i] == t[j])
                res += self(self, i + 1, j + 1) + self(self, i + 1, j);
            else
                res += self(self, i + 1, j);

            return memo[i][j] = res;
        };

        return dfs(dfs, 0, 0);
    }
};
// @lc code=end
