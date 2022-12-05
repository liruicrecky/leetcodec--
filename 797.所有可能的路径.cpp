// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;
        auto dfs = [&](auto &&self, int x) -> void {
            if (x == n - 1)
                res.push_back(path);

            for (const auto &idx : graph[x]) {
                path.push_back(idx);
                self(self, idx);
                path.pop_back();
            }
        };
        path.push_back(0);
        dfs(dfs, 0);

        return res;
    }
};
// @lc code=end
