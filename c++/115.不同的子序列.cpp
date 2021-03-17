/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    //dp考虑边界条件以及相应的状态转移方程  
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();

        if (m < n)
        {
            return 0;
        }
        
        vector<vector<long>> dp(m + 1, vector<long> (n + 1));
        for (int i = 0; i <= m; i++)
        {
            dp[i][n] = 1;
        }
        //一般从后往前遍历吗，会更好判断。
        for (int i = m - 1; i >= 0; i--)
        {
            char sh =  s.at(i);
            for (int j = n - 1; j >= 0; j--)
            {
                char th = t.at(j);
                if (sh == th)
                {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }   
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

