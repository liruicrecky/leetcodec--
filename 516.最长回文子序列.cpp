// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
  public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1));

        for (int i = 1; i <= n; i++)
            f[i][i] = 1;

        for (int i = n; i > 0; i--) {
            for (int j = i + 1; j <= n; j++) {
                if (s[i - 1] == s[j - 1])
                    f[i][j] = f[i + 1][j - 1] + 2;
                else
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }

        return f[1][n];
    }
};
// @lc code=end
