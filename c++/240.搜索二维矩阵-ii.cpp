/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)  return false;
        int col = 0;
        int row = matrix.size() - 1;
        while (col < matrix[0].size() && row > -1) 
        {
            if (matrix[row][col] > target) 
                row--;
            else if (matrix[row][col] < target) 
                col++;
            else return true;
        }
        return false;
    }
};
// @lc code=end

