// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
  private:
    int res = 0;
    vector<int> tmp;

    void mergeSort(vector<int> &nums, int l, int r) {
        if (l == r)
            return;

        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        merge(nums, l, mid, r);
    }

    void merge(vector<int> &nums, int l, int m, int r) {
        for (int i = l; i <= r; i++)
            tmp[i] = nums[i];

        
        int end = m + 1;
        for (int i = l; i <= m; i++) {
            while (end <= r && (long)tmp[i] > 2L * tmp[end])
                ++end;
            res += end - (m + 1);
        }
        

        int i = l, j = m + 1;
        for (int idx = l; idx <= r; idx++) {
            if (j == r + 1 || i < m + 1 && tmp[i] <= tmp[j]) {
                nums[idx] = tmp[i++];
            } else {
                nums[idx] = tmp[j++];
            }
        }
    }

  public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        tmp.resize(n);
        mergeSort(nums, 0, n - 1);

        return res;
    }
};
// @lc code=end
