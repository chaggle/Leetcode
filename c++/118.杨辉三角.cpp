/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    //迭代法
    /* vector<vector<int>> generate(int numRows) {
         vector<vector<int>> ret(numRows);
         for (int i = 0; i < numRows; i++)
         {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
            
         }
         return ret; */
    // 递归法
    vector<vector<int>> generate(int numRows) {
        vector<int> aws;
        vector<vector<int>> g;
        if (numRows == 0)
        {
            return g;
        }
        if (numRows == 1)
        {
            aws.push_back(1);
            g.push_back(aws);
            return g;
        }
        if (numRows == 2) {
            aws.push_back(1);
            g.push_back(aws);
            aws.push_back(1);
            g.push_back(aws);
            return g;
        }
        g = generate(numRows - 1);
        aws.push_back(1);
        for (int i = 0; i < numRows - 2; i++) 
        {

            aws.push_back(g[numRows-2][i] + g[numRows-2][i + 1]);
        }
        aws.push_back(1);
        g.push_back(aws);
        return g;        
    }
};
// @lc code=end

