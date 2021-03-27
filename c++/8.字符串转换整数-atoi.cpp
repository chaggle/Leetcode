/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, tmp = 0, i = 0;

        while(s[i] == ' ')  ++i;    //1.忽略前导空格

        if(s[i] == '+' || s[i] == '-')    //2.确定正负号
            sign = 1 - 2 * (s[i++] == '-');    //s[i]为+的话sign依旧为1，为-的话sign为-1

        while(s[i] >= '0' && s[i] <= '9')   //3.检查输入是否合法
        {
            if(tmp > INT_MAX / 10 || (tmp == INT_MAX / 10 && s[i] - '0' > 7))    //4.是否溢出
                return sign == 1 ? INT_MAX : INT_MIN;
            tmp = tmp * 10 + (s[i++] - '0');    //不加括号有溢出风险
        }
        return tmp * sign;
    }
};
// @lc code=end

