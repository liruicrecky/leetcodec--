// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
  private:
    void backtrack(vector<vector<int>> &res, vector<int> &nums,
                   vector<int> &tmp, vector<bool> &used) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            tmp.push_back(nums[i]);
            used[i] = true;
            backtrack(res, nums, tmp, used);
            used[i] = false;
            tmp.pop_back();
        }
    }

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        backtrack(res, nums, tmp, used);
        return res;
    }
};
// @lc code=end
