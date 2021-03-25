/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        int maxn = 0;
        for(int i : nums)
            maxn = max(maxn, i);
        vector<int> cnt(maxn + 1), dp(maxn + 1);

        for(int i : nums)
            cnt[i]++;

        dp[1] = cnt[1];

        for(int i = 2; i <= maxn; i++)
            dp[i] = max(dp[i-1], dp[i-2] + cnt[i] * i);
        return dp[maxn];
    }
};
// @lc code=end

