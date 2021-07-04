/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //桶排序做法
        vector<int> ans;
        int n = nums.size();
        int cnt[n + 1];
        memset(cnt, 0 , sizeof cnt);
        for (int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
            if (cnt[nums[i]] > 1)
            {
                ans.push_back(nums[i]);
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            if (cnt[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

