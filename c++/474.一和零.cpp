/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int maxtrix[m + 1][n + 1];
        memset(maxtrix, 0, sizeof(maxtrix));

        for(int i = 1; i <= strs.size(); i++)
        {
            string s = strs[i - 1];
            int len = s.length();
            int n0 = 0, n1 = 0;

            for(int l = 0; l < len; l++)
            {
                if(s[l] == '0')
                    n0++;
                else
                    n1++;
            }
            for(int j = m; j >= 0; j--)
            {
                for(int k = n; k >= 0; k--)
                {
                    if(n0 <= j && n1 <= k)
                        maxtrix[j][k] = max(maxtrix[j - n0][k - n1] + 1, maxtrix[j][k]);
                }
            }
        }
        return maxtrix[m][n];
    }
};
// @lc code=end

