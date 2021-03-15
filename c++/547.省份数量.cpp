/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    //1.深度优先遍历，使用
    void dfs(vector<vector<int>>&isConnected, vector<int>& visited, int provinces, int i)
    {
        for (int j = 0; j < provinces; j++)
        {
            if (isConnected[i][j] == 1 && !visited[j])
            {
                visited[j] = 1;
                dfs(isConnected, visited, provinces, j);
            }
        }   
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<int> visited(provinces);
        int cicles = 0;
        for (int i = 0; i < provinces; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, visited, provinces, i);
                cicles++;
            }
        }
        return cicles;
    }
/**************************************************************/
    //2.广度优先遍历算法，用队列进行实现
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<int> visited(provinces);
        int circles = 0;
        queue<int> Q;
        for (int i = 0; i < provinces; i++)
        {
            if (!visited[i])
            {
                Q.push(i);
                while (!Q.empty())
                {
                    int j = Q.front();
                    Q.pop();
                    visited[j] = 1;
                    for (int k = 0;  k < provinces; k++)
                    {
                        if (isConnected[j][k] == 1 && !visited[k])
                        {
                            Q.push(k);
                        }
                        
                    }
                    
                }
                circles++;
            }
            
        }
        return circles;
    };
};
// @lc code=end

