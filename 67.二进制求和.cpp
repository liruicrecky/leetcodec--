// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
  public:
    string addBinary(string a, string b) {
        if (a.size() == 1 && a[0] == '0')
            return b;
        if (b.size() == 1 && b[0] == '0')
            return a;

        string ans = "";
        int n = a.size(), m = b.size();
        int carry = 0, sum = 0;
        int i = n - 1, j = m - 1;

        while (i >= 0 || j >= 0) {
            sum = 0;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            sum += carry;
            carry = sum / 2;
            sum %= 2;
            ans += to_string(sum);
        }

        if (carry)
            ans += '1';

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end
