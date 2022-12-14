// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
  private:
    bool canFinishBFS(int numCourses, vector<vector<int>> &prerequisites) {
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
        while (!que.empty()) {
            auto node = que.front();
            que.pop();
            ++count;
            for (const auto &next : g[node]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    que.push(next);
            }
        }

        return count == numCourses;
    }

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> g(numCourses);
        for (const auto &pre : prerequisites)
            g[pre[1]].push_back(pre[0]);

        vector<bool> visited(numCourses, false), path(numCourses, false);
        bool cycle = false;
        auto dfs = [&](auto &&self, int x) {
            if (path[x])
                cycle = true;
            if (visited[x] || cycle)
                return;
            visited[x] = true;
            path[x] = true;
            for (const auto &ne : g[x])
                self(self, ne);
            path[x] = false;
        };

        for (int i = 0; i < numCourses; i++)
            dfs(dfs, i);

        return !cycle;
        // return canFinishBFS(numCourses, prerequisites);
    }
};
// @lc code=end
