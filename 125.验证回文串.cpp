// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
  public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < r && !isalpha(s[l]) && !isdigit(s[l]))
                ++l;
            while (l < r && !isalpha(s[r]) && !isdigit(s[r]))
                --r;

            if (tolower(s[l]) != tolower(s[r]))
                return false;
            ++l, --r;
        }

        return true;
    }
};
// @lc code=end
