// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
  private:
    vector<int> tmp;
    void sort(vector<int> &nums) {
        tmp.resize(nums.size());
        sort(nums, 0, nums.size() - 1);
    }

    void sort(vector<int> &nums, int l, int r) {
        if (l == r) {
            return;
        }

        int m = l + (r - l) / 2;

        sort(nums, l, m);
        sort(nums, m + 1, r);

        merge(nums, l, m, r);
    }

    void merge(vector<int> &nums, int l, int m, int r) {
        for (int i = l; i <= r; i++) {
            tmp[i] = nums[i];
        }

        int i = l, j = m + 1;
        for (int idx = l; idx <= r; idx++) {
            if (i == m + 1) {
                nums[idx] = tmp[j++];
            } else if (j == r + 1) {
                nums[idx] = tmp[i++];
            } else if (tmp[i] > tmp[j]) {
                nums[idx] = tmp[j++];
            } else {
                nums[idx] = tmp[i++];
            }
        }
    }

  public:
    vector<int> sortArray(vector<int> &nums) {
        sort(nums);
        return nums;
    }
};
// @lc code=end
