/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    //撞墙法，寻找边界条件法。
   /*  vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ret(n, vector<int>(n));
        int up = 0, down = n-1, left = 0, right = n-1;
        int num = 0;
        while (num != n*n)
        {
            for (int i = left; i <= right; i++)
            {
                ret[up][i] = ++num;
            }
            for (int i = up + 1; i <= down; i++)
            {
                ret[i][right] = ++num;
            }
            for (int i = right - 1; i >= left; i--)
            {
                ret[down][i] = ++num;
            }
            for (int i = down - 1; i > up; i--)
            {
                ret[i][left] = ++num;
            }
            ++up;
            --down;
            ++left;
            --right;           
        }
        return ret;
    } */
    vector<vector<int>> generateMatrix(int n) {
            
    }
};
// @lc code=end

