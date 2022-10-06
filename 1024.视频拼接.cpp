// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
class Solution {
  public:
    int videoStitching(vector<vector<int>> &clips, int time) {
        sort(clips.begin(), clips.end(), [](const auto &a, const auto &b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            else
                return a[0] < b[0];
        });

        int n = clips.size();
        int curEnd = 0, nextEnd = 0;
        int cnt = 0, idx = 0;

        while (idx < n && clips[idx][0] <= curEnd) {
            while (idx < n && clips[idx][0] <= curEnd) {
                nextEnd = max(nextEnd, clips[idx][1]);
                ++idx;
            }

            ++cnt;
            curEnd = nextEnd;
            if (curEnd >= time)
                return cnt;
        }

        return -1;
    }
};
// @lc code=end
