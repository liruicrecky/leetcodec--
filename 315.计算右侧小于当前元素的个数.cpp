// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
    using PII = pair<int, int>;

  private:
    vector<PII> tmp, pos;

    void sort(int l, int r, vector<int> &res) {
        if (l == r) {
            return;
        }

        int m = l + (r - l) / 2;

        sort(l, m, res);
        sort(m + 1, r, res);

        merge(l, m, r, res);
    }

    void merge(int l, int m, int r, vector<int> &res) {
        for (int i = l; i <= r; i++) {
            tmp[i] = pos[i];
        }

        int i = l, j = m + 1;
        for (int idx = l; idx <= r; idx++) {
            if (j == r + 1 || i < m + 1 && tmp[i].first <= tmp[j].first) {
                pos[idx] = tmp[i++];
                res[pos[idx].second] += j - m - 1;
            } else {
                pos[idx] = tmp[j++];
            }
        }
    }

  public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n);
        tmp.resize(n);
        pos.resize(n);
        for (int i = 0; i < n; i++) {
            pos[i] = {nums[i], i};
        }

        sort(0, n - 1, res);
        return res;
    }
};
// @lc code=end
