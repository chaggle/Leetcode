/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int  i = 1; i <= m; i++)
        {
            char c1 = text1.at(i - 1);
            for (int j = 1; j <= n; j++)
            {
                char c2= text2.at(j - 1);
                if(c1 == c2)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        } 
        return dp[m][n];
    }
};
// @lc code=end

