// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution {
  public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        vector<bool> color(n + 1, false), visited(n + 1, false);
        vector<vector<int>> g(n + 1);
        bool ok = true;
        for (const auto &edge : dislikes) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        auto dfs = [&](auto &&self, int x) {
            if (!ok)
                return;
            visited[x] = true;
            for (const auto &next : g[x]) {
                if (!visited[next]) {
                    color[next] = !color[x];
                    self(self, next);
                } else {
                    if (color[next] == color[x]) {
                        ok = false;
                        return;
                    }
                }
            }
        };

        for (int i = 1; i <= n; i++)
            if (!visited[i])
                dfs(dfs, i);

        return ok;
    }
};
// @lc code=end
