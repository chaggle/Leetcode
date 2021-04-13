/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for(auto x : nums) vs.push_back(to_string(x));
        sort(vs.begin(),vs.end(),[](const auto& A,const auto& B)
        {
            return A + B > B + A;
        });
        string ans;
        for(const auto& x : vs) ans += x;
        return ans[0] == '0' ? "0" : ans; 
    }
};
// @lc code=end

