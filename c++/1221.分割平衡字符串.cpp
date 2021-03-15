/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution {
public:
    //面试的时候，先要静下心来看题目，没有题目就有问题
    int balancedStringSplit(string s) {
        int res = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'R')
                count++;
            else
                count--;
            if(count == 0)
                res++;
        }
        return res;
    }
};
// @lc code=end

