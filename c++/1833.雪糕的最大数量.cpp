/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (coins >= costs[i])
            {
                ans++;
                coins -= costs[i];
            }
        }
        return ans;
    }
};
// @lc code=end

