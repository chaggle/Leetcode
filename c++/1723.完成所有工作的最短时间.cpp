/*
 * @lc app=leetcode.cn id=1723 lang=cpp
 *
 * [1723] 完成所有工作的最短时间
 */

// @lc code=start
class Solution {
public: 
    int ans = INT_MAX;
    int len, k;
    //dfs也是基于递归的基础之上进行提交的。
    int minimumTimeRequired(vector<int>& jobs, int _k) {
        len = jobs.size();
        k = _k;
        vector<int> res(k, 0);
        dfs(res, jobs, 0, 0, 0);
        return ans;
    }

    void dfs(vector<int>& res, vector<int>& jobs, int used, int index, int m) {
        if (ans < m) return;

        if (index == len) {
            ans = m;
            return;
        }

        if (used < k) {
            res[used] = jobs[index];
            dfs(res, jobs, used + 1, index + 1, max(m, res[used]));
            res[used] = 0;
        }

        for (int i = 0; i < used; i++) {
            res[i] += jobs[index];
            dfs(res, jobs, used, index + 1, max(m, res[i]));
            res[i] -= jobs[index];
        }
    }
};
// @lc code=end

