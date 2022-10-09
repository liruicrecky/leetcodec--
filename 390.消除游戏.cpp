/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
class Solution {
  public:
    int lastRemaining(int n) {
        int first = 1, step = 1, remain = n;
        bool isLeft = true;
        while (remain > 1) {
            if (isLeft || ((remain & 1) == 1))
                first += step;
            isLeft = !isLeft;
            step <<= 1;
            remain >>= 1;
        }

        return first;
    }
};
// @lc code=end
