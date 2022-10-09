// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=939 lang=cpp
 *
 * [939] 最小面积矩形
 */

// @lc code=start
class Solution {
  public:
    int minAreaRect(vector<vector<int>> &points) {
        unordered_set<int> set;
        for (const auto &point : points)
            set.insert(40001 * point[0] + point[1]);

        int ans = INT_MAX, n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int ax = points[i][0], ay = points[i][1];
                int bx = points[j][0], by = points[j][1];
                if (ax == bx || ay == by)
                    continue;

                if (set.count(40001 * ax + by) && set.count(40001 * bx + ay))
                    ans = min(ans, abs(ax - bx) * abs(ay - by));
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
