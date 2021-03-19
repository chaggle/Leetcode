/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ans = 1;

        int dp[n][2];

        for (int i = 0; i < 2; i++)
        {
            dp[0][i] = 1;
        }

        for (size_t i = 1; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i][j] = 1;
            }
            if (arr[i - 1] < arr[i])
            {
                dp[i][0] = dp[i - 1][1] + 1;
            }
            if (arr[i - 1] > arr[i])
            {
                dp[i][1] = dp[i - 1][0] + 1;
            }

            for (int j = 0; j < 2; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end

