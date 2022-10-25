// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;
        for (const auto &num : nums)
            set.insert(num);

        int maxLen = 0;
        for (const auto &num : set) {
            if (!set.count(num - 1)) {
                int cur = num, len = 1;
                while (set.count(cur + 1)) {
                    cur++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
// @lc code=end
