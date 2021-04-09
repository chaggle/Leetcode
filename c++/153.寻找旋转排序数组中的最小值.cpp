/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + right + 1 >> 1;
            if(nums[left] <= nums[mid]) 
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return right + 1 < nums.size() ? nums[right + 1] : nums[0];
    }
};
// @lc code=end

