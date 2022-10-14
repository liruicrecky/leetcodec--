// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
  private:
    bool backtrack(int k, int bucket, vector<int> &nums,
                   unordered_map<int, bool> &memo, int s, int used,
                   int target) {
        if (k == 0)
            return true;

        if (bucket == target) {
            bool res = backtrack(k - 1, 0, nums, memo, 0, used, target);
            memo.insert({used, res});
            return res;
        }

        if (memo.count(used))
            return memo.at(used);

        for (int i = s; i < nums.size(); i++) {
            if (((used >> i) & 1) == 1)
                continue;
            if (nums[i] + bucket > target)
                continue;

            used |= 1 << i;
            bucket += nums[i];
            if (backtrack(k, bucket, nums, memo, i + 1, used, target))
                return true;
            used ^= 1 << i;
            bucket -= nums[i];
        }

        return false;
    }

  public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0 || k > n)
            return false;

        int used = 0;
        int target = sum / k;
        unordered_map<int, bool> memo;
        return backtrack(k, 0, nums, memo, 0, used, target);
    }
};
// @lc code=end
