/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    //二维超时了
    bool stoneGame(vector<int>& piles) {
       /*  int n = piles.size();
        auto dp = vector<int>(n);

        for (int i = 0; i < n; i++) 
        {
            dp[i] = piles[i];
        }
        
        for (int i = n - 2; i >= 0; i--) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] > 0; */
        return true;
    }
};
// @lc code=end

