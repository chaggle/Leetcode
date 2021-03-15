/*
 * @lc app=leetcode.cn id=1402 lang=cpp
 *
 * [1402] 做菜顺序
 */

// @lc code=start
class Solution {
public:
    //贪心法的
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int size = satisfaction.size();
        if (satisfaction[size-1] <= 0)
        {
            return 0;
        }
        vector<int> dp(size, 0);
        dp[size - 1] = satisfaction[size-1];
        for (int i = size-2; i >= 0; i--)
        {
            int temp = 0;
            for (int j = size - 1; j >= i; j--)
            {
                temp += satisfaction[j];
            }
            dp[i] = max(dp[i + 1], dp[i + 1]+temp);
        }
        return dp[0];
    }
};
// @lc code=end

