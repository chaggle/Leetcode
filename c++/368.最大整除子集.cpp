/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);

        for (int i = 0; i < n; i++)
        {
            // 至少包含自身一个数，因此起始长度为 1，由自身转移而来     
            int len = 1, prev = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if(f[j] + 1 > len)
                    {
                        // 如果能接在更长的序列后面，则更新「最大长度」&「从何转移而来」
                        len = f[j] + 1;
                        prev = j;
                    }
                } 
            } 
            f[i] = len;
            g[i] = prev;  
        }
         // 遍历所有的 f[i]，取得「最大长度」和「对应下标」
        int idx = max_element(f.begin(), f.end()) - f.begin();
        int max = f[idx];

        // 使用 g[] 数组回溯出具体方案
        vector<int> ans;
        while (ans.size() != max)
        {
            ans.push_back(nums[idx]);
            idx = g[idx];
        }
        return ans;
    }
};
// @lc code=end

