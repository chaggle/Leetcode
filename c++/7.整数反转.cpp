/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
       long num = 0;
       while (x)
       {
           num = num * 10 + x % 10;
           x /= 10; 
       }
       if (x < 0)
       {
           num *= -1;
       }
       if(num < INT_MIN || num> INT_MAX)
            num = 0;
        return num;
    }
};
// @lc code=end

