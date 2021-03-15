/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    /* const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int idx = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        for(int x = 0, y = 0, d = 0; idx < m * n; idx++)
        {
            res.push_back(matrix[x][y]);
            matrix[x][y] = 101;  
            int t_x = x + dir[d][0], t_y = y + dir[d][1];
            if(t_x < 0 || t_x >= m || t_y < 0 || t_y >= n || matrix[t_x][t_y] == 101)
            {
                d = (d + 1) % 4;
                t_x = x + dir[d][0],t_y = y + dir[d][1];
            }
            x = t_x, y = t_y;
        }
        return res; */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty())
        {
            return ans;
        }
        int up = 0;//上边界预定值
        int down = matrix.size() - 1;

        int left = 0;//左边界定值
        int right = matrix[0].size() - 1;
        while (true)
        {
            for (int i = left; i <= right; i++)//向右移动直到最右
            {
                ans.push_back(matrix[up][i]);
            }
            if (++up > down)//重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            {
                break;
            }
            for (int i = up; i <=down ; i++)//向下
            {
                ans.push_back(matrix[i][right]);
            }
            if (--right < left)//重新设定右边界
            {
                break;
            }
            for(int i = right; i >= left; --i) //向左
            {
                ans.push_back(matrix[down][i]); 
            }
            if(--down < up) //重新设定下边界
            {
                break; 
            }
            for(int i = down; i >= up; --i)  //向上
            {
                ans.push_back(matrix[i][left]);
            }
            if(++left > right) //重新设定左边界
            {
                break; 
            }
        }
        return ans;
    }
};
// @lc code=end

