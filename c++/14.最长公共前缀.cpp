/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    // 此方法确实类似解两题，空间与时间复杂度都没有做到最优化
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return string();
        sort(strs.begin(), strs.end());
        string front = strs.front(), end = strs.back();
        int i, num = min(front.size(), end.size());
        for(i = 0; i < num && front[i] == end[i]; i++);
        return string(front, 0, i);
    }
};
// @lc code=end

