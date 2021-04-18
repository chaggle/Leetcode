/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int tmp = 0;
        for (int i = 0; i< n; i++) {
            if(nums[tmp] != nums[i]) {
                nums[++tmp] = nums[i];
            }
        }
        return tmp + 1;
    }
};
// @lc code=end

