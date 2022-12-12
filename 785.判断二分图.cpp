// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
  private:
    bool isBipartiteBFS(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<bool> visited(n, false), color(n);
        bool ok = true;

        auto bfs = [&](int x) {
            queue<int> que;
            que.push(x);
            visited[x] = true;
            while (!que.empty() && ok) {
                auto node = que.front();
                que.pop();
                for (const auto &next : graph[node]) {
                    if (!visited[next]) {
                        color[next] = !color[node];
                        visited[next] = true;
                        que.push(next);
                    } else {
                        if (color[next] == color[node]) {
                            ok = false;
                            return;
                        }
                    }
                }
            }
        };

        for (int i = 0; i < n; i++)
            if (!visited[i])
                bfs(i);

        return ok;
    }

  public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<bool> visited(n, false), color(n);
        bool ok = true;
        auto dfs = [&](auto &&self, int x) -> void {
            if (!ok)
                return;
            visited[x] = true;
            for (const auto &next : graph[x]) {
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

        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(dfs, i);

        return ok;
        // return isBipartiteBFS(graph);
    }
};
// @lc code=end
