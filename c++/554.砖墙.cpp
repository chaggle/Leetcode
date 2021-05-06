/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int, int> map;
        for (int i = 0, sum = 0; i< n; i++, sum = 0) {
            for (int cur : wall[i]) {
                sum += cur;
                map[sum]++;
            }
            map.erase(sum); //无法从两边穿过
        }
        
        int ans = n;
        for (auto & [u, cnt] : map ) {
            ans = min(ans, n - cnt);
        }
        return ans;
    }
};
// @lc code=end

