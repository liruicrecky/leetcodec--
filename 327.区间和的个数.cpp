// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {
  private:
    vector<long> tmp, preSum;
    int _lower, _upper;
    int res = 0;
    void mergeSort(vector<long> &nums, int l, int r) {
        if (l == r)
            return;

        int m = l + (r - l) / 2;

        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);

        for (int i = l; i <= r; i++)
            tmp[i] = nums[i];

        int s = m + 1, e = m + 1;
        for (int i = l; i <= m; i++) {
            while (s <= r && nums[s] - nums[i] < _lower)
                ++s;
            while (e <= r && nums[e] - nums[i] <= _upper)
                ++e;
            res += e - s;
        }

        int i = l, j = m + 1;
        for (int idx = l; idx <= r; idx++) {
            if (j == r + 1 || i < m + 1 && tmp[i] <= tmp[j])
                nums[idx] = tmp[i++];
            else
                nums[idx] = tmp[j++];
        }
    }

  public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        tmp.resize(n + 1);
        preSum.resize(n + 1);
        _lower = lower;
        _upper = upper;
        for (int i = 1; i <= n; i++)
            preSum[i] = preSum[i - 1] + nums[i - 1];

        mergeSort(preSum, 0, n);
        return res;
    }
};
// @lc code=end
