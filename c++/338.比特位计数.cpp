/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        int highbit = 0;
        for (int i = 1; i <= num; i++)
        {
            if((i & (i - 1)) == 0)
            {
                highbit = i;
            }
            dp[i] = dp[i - highbit] + 1;
        }
        return dp;
    }
};
// @lc code=end

