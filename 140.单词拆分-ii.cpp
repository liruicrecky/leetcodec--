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
  private:
    void dfs(vector<string> &res, vector<string> &wordDict, string &tmp,
             vector<bool> &f, int idx) {
        if (idx == f.size() - 1 && f[idx]) {
            tmp.pop_back();
            res.push_back(tmp);
        } else {
            for (const auto &word : wordDict) {
                int sz = word.size();
                if (idx >= sz && f[idx - sz]) {
                    tmp.append(word + " ");
                    cout<< word << " " <<tmp << "\n";
                    dfs(res, wordDict, tmp, f, idx + sz);
                    tmp.erase(idx);
                }
            }
        }
    }

  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
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

        if (!f[n])
            return vector<string>{};

        vector<string> res;
        string tmp;
        dfs(res, wordDict, tmp, f, n);

        return res;
    }
};
// @lc code=end
