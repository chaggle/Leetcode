/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    //动态规划稍微显得复杂，或许贪心法能更好的解决相应的问题
    /* bool canJump(vector<int>& nums) {
        int n = nums.size();
        //熟悉动态规划算法的，dp[i]表示从数组下标0出发，是否可以到达i处位置；
        vector<int> dp(n, 0);
        dp[0] = 1;

        //dp中最重要的就是状态转移方程，状态转移方程理解的越好，动态规划理解也就越好
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if((dp[j] == 1) && nums[j] >= i - j) //状态方程
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n-1];
    } */
    //贪心法
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int most = 0;
        for (int i = 0; i < n; i++)
        {
            if (i <= most)
            {
                most = max(most, i + nums[i]);
                if (most >= n - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

