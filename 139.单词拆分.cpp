// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<bool> f(n + 1, false);
        f[0] = true;

        for (int i = 1; i <= n; i++) {
            for (const auto &word : wordDict) {
                int sz = word.size();
                if (i >= sz) {
                    if (f[i - sz] && st.count(s.substr(i - sz, sz))) {
                        f[i] = true;
                        break;
                    }
                }
            }
        }

        return f[n];
    }
};
// @lc code=end
