/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        vector<vector<string>>::iterator it;
        int ans = 0;
        for (it = items.begin(); it < items.end(); it++) {
            if (((ruleKey == "type") && (*it)[0] == ruleValue) || (((ruleKey == "color") && (*it)[1] == ruleValue)) || (((ruleKey == "name") && (*it)[2] == ruleValue))) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

