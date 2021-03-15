/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        if (n < 2)
        {
            return n;
        }
        
        vector<int> nums(n, 1);

        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i-1])
            {
                nums[i] = nums[i-1] + 1;
            }
        }

        for (int i = n - 1; i > 0; --i)
        {
            if (ratings[i] < ratings[i-1])
            {
                nums[i - 1] = max(nums[i-1],nums[i] + 1);
            }
            
        }
        
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end

