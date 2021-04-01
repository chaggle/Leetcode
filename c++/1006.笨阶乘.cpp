/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution {
public:
    //数学方法解决问题，化简式子可以得到相应的逻辑关系
    int clumsy(int n) {
        if(n == 1) return 1;
        else if(n == 2) return 2;
        else if(n == 3) return 6;
        else if(n == 4) return 7;

        if(n % 4 == 0) return n + 1;
        else if(n % 4 <= 2) return n + 2;
        else return n - 1;
    }
};
// @lc code=end

