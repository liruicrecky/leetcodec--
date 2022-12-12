// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
  private:
    vector<int> findOrderBFS(int numCourses,
                             vector<vector<int>> &prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses, 0);
        for (const auto &edge : prerequisites) {
            indegree[edge[0]]++;
            g[edge[1]].push_back(edge[0]);
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                que.push(i);
        }

        int count = 0;
        vector<int> res;

        while (!que.empty()) {
            auto node = que.front();
            que.pop();
            res.push_back(node);
            count++;
            for (const auto &next : g[node]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    que.push(next);
            }
        }

        if (count != numCourses)
            return {};
        return res;
    }

  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> g(numCourses);
        for (const auto &pre : prerequisites)
            g[pre[1]].push_back(pre[0]);

        bool cycle = false;
        vector<bool> path(numCourses), visited(numCourses);
        vector<int> res;

        auto dfs = [&](auto &&self, int x) {
            if (path[x])
                cycle = true;
            if (visited[x] || cycle)
                return;
            path[x] = true;
            visited[x] = true;
            for (const auto &ne : g[x])
                self(self, ne);
            res.push_back(x);
            path[x] = false;
        };

        for (int i = 0; i < numCourses; i++)
            dfs(dfs, i);

        if (cycle)
            return {};
        reverse(res.begin(), res.end());
        return res;
        // return findOrderBFS(numCourses, prerequisites);
    }
};
// @lc code=end
