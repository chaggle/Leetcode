/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> umap;
        int n = nums.size();
        int i = 0;
        for (; i < n; i++)
        {
            ++umap[nums[i]];
            if (umap[nums[i]] > n / 2)
            {
                return nums[i];
            }
        }
        return nums[i];
    }
};
// @lc code=end

