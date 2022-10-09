// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
  public:
    string decodeString(string s) {
        string ans = "";
        deque<char> stk;
        deque<int> dig;
        int bit = 0;

        for (const auto &c : s) {
            if (c == ']') {
                string tmp = "";
                while (stk.front() != '[') {
                    tmp += stk.front();
                    stk.pop_front();
                }
                stk.pop_front();

                reverse(tmp.begin(), tmp.end());

                int n = dig.front();
                dig.pop_front();

                int idx = 0;
                for (int i = 0; i < n; i++) {
                    idx += dig.front() * pow(10, i);
                    dig.pop_front();
                }

                while (idx--)
                    for (const auto &cc : tmp)
                        stk.push_front(cc);
            } else if (isdigit(c)) {
                ++bit;
                dig.push_front(c - '0');
            } else if (c == '[') {
                stk.push_front(c);
                dig.push_front(bit);
                bit = 0;
            } else
                stk.push_front(c);
        }

        while (!stk.empty()) {
            ans += stk.back();
            stk.pop_back();
        }

        return ans;
    }
};
// @lc code=end
