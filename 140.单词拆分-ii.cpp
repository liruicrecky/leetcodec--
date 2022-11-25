// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<bool> f(n + 1, false);
        f[0] = true;

        vector<vector<string>> res;
        vector<string> tmp;

        function<void(int)> dfs = [&](int idx) {
            if (idx == n + 1 && f[n]) {
                res.push_back(tmp);
                return;
            }

            for (int i = idx; i <= n; i++) {
                for (const auto &word : wordDict) {
                    int sz = word.size();
                    if (i - idx + 1 >= sz && f[i - sz]) {
                        auto subWord = s.substr(i - sz, sz);
                        if (st.count(subWord)) {
                            f[i] = true;
                            tmp.push_back(subWord);
                            dfs(idx + sz);
                            f[i] = false;
                            tmp.pop_back();
                            break; // important
                        }
                    }
                }
            }
        };

        dfs(1);

        vector<string> ans;
        for (const auto &r : res) {
            string sub = "";
            for (const auto &w : r)
                sub += w + " ";
            sub.pop_back();
            ans.push_back(sub);
        }

        return ans;
    }
};
// @lc code=end
