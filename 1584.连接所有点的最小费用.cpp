// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
class Solution {
    class UnionFind {
      private:
        vector<int> _parent;
        int _count;

      private:
        inline int find(int x) {
            return x != _parent[x] ? _parent[x] = find(_parent[x]) : x;
        }

      public:
        UnionFind(int n) {
            _parent.resize(n);
            _count = n;

            for (int i = 0; i < n; i++)
                _parent[i] = i;
        }

        inline int count() { return _count; }

        inline bool connected(int p, int q) { return find(p) == find(q); }

        void unioN(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);

            if (rootP == rootQ)
                return;

            _parent[rootQ] = rootP;
            --_count;
        }
    };

  public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        auto distance = [](int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };

        int n = points.size();
        vector<tuple<int, int, int>> g;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dis = distance(x1, y1, x2, y2);
                g.push_back({i, j, dis});
            }
        }

        sort(g.begin(), g.end(), [](const auto &t1, const auto &t2) {
            return get<2>(t1) < get<2>(t2);
        });

        UnionFind uf(n);
        int res = 0;
        for (const auto &edge : g) {
            auto [p, q, w] = edge;
            if (uf.connected(p, q))
                continue;

            res += w;
            uf.unioN(p, q);
        }

        return res;
    }
};
// @lc code=end
