/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size(), k = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            if(nums[i] < k)
                return true;
            while (!stk.empty() && stk.top() < nums[i])
            {
                k = max(k, stk.top());
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end

