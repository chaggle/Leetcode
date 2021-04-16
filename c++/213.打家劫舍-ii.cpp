/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    //空间非最优化，也是两遍dp遍历，同时也能分两种情况。
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(subrob(nums, 0, n - 2), subrob(nums, 1, n - 1));
    }

    int subrob(vector<int>& nums, int begin, int end)
    {
        int premax =  0, curmax = 0;
        for (int i = begin; i <= end; i++)
        {
            int temp = curmax;
            curmax  = max(nums[i] + premax, curmax);
            premax = temp;
        }
        return curmax;
    }
};
// @lc code=end

