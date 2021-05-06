/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size() + 1;
        vector<int> ans(n, 0);
        ans[0] = first;
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] ^ encoded[i - 1];
        }
        return ans;
    }
};
// @lc code=end

