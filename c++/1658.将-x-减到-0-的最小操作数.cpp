/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = INT_MAX;
        int target = accumulate(nums.begin(), nums.end(),0) - x;
        if(target == 0)
            return n;
        int left = 0, right = 0, sum = 0;
        while(right < n)
        {
            sum += nums[right];
            while(sum > target && left < right)
            {
                sum -= nums[left];
                ++left; 
            }
            if(sum == target)
                ans = min(ans, n-1 + left-right);
            ++right;
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};
// @lc code=end

