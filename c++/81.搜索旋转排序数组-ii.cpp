/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //在left~right之间进行二分查找
        for (int left = 0, right = nums.size() - 1, mid; left <= right;)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            else if(nums[left] < nums[mid])
            {
                //target位于左半部分，到右半部分二分查找
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if (nums[mid] <nums[right])
            {
                //target位于右半部分，到右半部分二分查找
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else {
                while (left <= right && nums[mid] == nums[left])left++;
                while (left <= right && nums[right] == nums[mid])right--;
            }
        }
        return false;        
    }
};
// @lc code=end

