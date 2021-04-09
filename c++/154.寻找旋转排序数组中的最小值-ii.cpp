/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right && nums[0] == nums[right]) right--;
        while (left < right)
        {
            int mid = left + right + 1 >> 1;
            if (nums[mid] >= nums[0])
            {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return right + 1 < n ? nums[right + 1] : nums[0];
    }
};
// @lc code=end

