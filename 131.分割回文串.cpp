// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
  public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> tmp;

        auto check = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r])
                    return false;
                ++l, --r;
            }
            return true;
        };

        auto backTrace = [&](auto &&self, int idx) {
            if (idx > n - 1) {
                res.push_back(tmp);
                return;
            }

            for (int i = 1; i <= n - idx; i++) {
                if (check(idx, idx + i - 1)) {
                    tmp.push_back(s.substr(idx, i));
                    self(self, idx + i);
                    tmp.pop_back();
                }
            }
        };

        backTrace(backTrace, 0);

        return res;
    }
};
// @lc code=end
