// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
  public:
    string smallestSubsequence(string s) {
        stack<char> stk;
        vector<int> count(256, 0);

        for (const auto &c : s)
            count[c]++;

        vector<bool> inStk(256, false);
        for (const auto &c : s) {
            count[c]--;

            if (inStk[c])
                continue;

            while (!stk.empty() && stk.top() > c) {
                if (count[stk.top()] == 0)
                    break;

                inStk[stk.top()] = false;
                stk.pop();
            }

            stk.push(c);
            inStk[c] = true;
        }

        string ans = "";
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end
