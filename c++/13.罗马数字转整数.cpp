/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(int num) {
        string strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int ans[];
        for (int i = 0; num > 0 && i < 13; i++)
        {
            while (nums[i] <= num)
            {
                 += strs[i];
                num -= nums[i];
            }
        }
        return ans;
    }
};
// @lc code=end

