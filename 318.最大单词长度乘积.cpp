// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
  public:
    int maxProduct(vector<string> &words) {
        int n = words.size();
        int maxLen = 0;
        vector<int> hash(n);

        for (int i = 0; i < n; i++)
            for (const auto &c : words[i])
                hash[i] |= 1 << (c - 'a');

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((hash[i] & hash[j]) == 0)
                    maxLen =
                        max(maxLen, (int)(words[i].size() * words[j].size()));
            }
        }

        return maxLen;
    }
};
// @lc code=end
