// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int n = s1.size(), m = s2.size();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;

        for (int i = 1; i <= n && s1[i - 1] == s3[i - 1]; i++)
            f[i][0] = true;

        for (int j = 1; j <= m && s2[j - 1] == s3[j - 1]; j++)
            f[0][j] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                f[i][j] = (f[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                          (f[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }

        return f[n][m];
    }
};
// @lc code=end
