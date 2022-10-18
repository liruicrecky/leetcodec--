// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
  private:
    int dp(string &s1, int i, string &s2, int j, vector<vector<int>> &memo) {
        int res = 0;
        if (i == s1.length()) {
            while (j < s2.length()) {
                res += s2[j];
                j++;
            }
            return res;
        }

        if (j == s2.length()) {
            while (i < s1.length()) {
                res += s1[i];
                i++;
            }
            return res;
        }

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s1[i] == s2[j])
            memo[i][j] = dp(s1, i + 1, s2, j + 1, memo);
        else
            memo[i][j] = min(s1[i] + dp(s1, i + 1, s2, j, memo),
                             s2[j] + dp(s1, i, s2, j + 1, memo));

        return memo[i][j];
    }

  public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return dp(s1, 0, s2, 0, memo);
    }

    int minimumDeleteSum1(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
            f[i][0] = f[i - 1][0] + s1[i - 1];

        for (int j = 1; j <= m; j++)
            f[0][j] = f[0][j - 1] + s2[j - 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] =
                        min({s1[i - 1] + f[i - 1][j], s2[j - 1] + f[i][j - 1],
                             s1[i - 1] + s2[j - 1] + f[i - 1][j - 1]});
            }
        }

        return f[n][m];
    }
};
// @lc code=end
