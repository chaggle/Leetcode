/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    //动态规划思想解决问题
    int numDecodings(string s) {
        int n = s.size();
        s = " " + s; //使用空格哨兵
        int f[3];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i % 3] = 0;
            int a = s[i] - '0', b = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (1 <= a && a <= 9)  f[i % 3] = f[(i - 1) % 3];
            if (10 <= b && b <= 26) f[i % 3] += f[(i - 2) % 3];
        }
        return f[n % 3];
    }
};
// @lc code=end

