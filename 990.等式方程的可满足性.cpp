// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
    class UnionFind {
      private:
        int _count;
        vector<int> _parent;

      private:
        int find(int x) {
            if (_parent[x] != x)
                _parent[x] = find(_parent[x]);
            return _parent[x];
        }

      public:
        UnionFind(int n) {
            _count = n;
            _parent.resize(n);

            for (int i = 0; i < n; i++)
                _parent[i] = i;
        }

        inline int count() { return _count; }

        bool connected(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            return rootP == rootQ;
        }

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
    bool equationsPossible(vector<string> &equations) {
        UnionFind uf(26);
        for (const auto &e : equations) {
            if (e[1] == '=')
                uf.unioN(e[0] - 'a', e[3] - 'a');
        }

        for (const auto &e : equations) {
            if (e[1] == '!') {
                if (uf.connected(e[0] - 'a', e[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end
