// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
  public:
    string simplifyPath(string path) {
        vector<string> stk;
        istringstream iss(path);
        string input;

        while (getline(iss, input, '/')) {
            if (!input.empty() && input != "." && input != "..")
                stk.push_back(input);
            else if (!stk.empty() && input == "..")
                stk.pop_back();
        }

        if (stk.empty())
            return "/";

        input.clear();
        for (const auto &s : stk) {
            input += "/" + s;
        }

        return input;
    }
};
// @lc code=end
