/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void backtrack(vector<int>& nums, vector<int>& path, int pos) {
        if (pos == n) {
            if (path.size() >= 2)
                ans.push_back(path);
            return;
        }
        
        if (path.empty() || path.back() <= nums[pos]) {
            path.push_back(nums[pos]);
            backtrack(nums, path, pos + 1);
            path.pop_back();
        }

        if (!path.empty() && pos > 0 && path.back() == nums[pos])
            return;
        backtrack(nums, path, pos + 1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> path;
        backtrack(nums, path, 0);
        return ans;
    }
};
// @lc code=end

