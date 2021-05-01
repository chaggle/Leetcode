/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                 sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int ans = INT_MIN;
        for (int top = 1; top <= m; top++) {
            for (int bot = top; bot <= m; bot++) {
                set<int> st;
                st.insert(0);
                for (int r = 1; r <= n; r++) {
                    int right = sum[bot][r] - sum[top - 1][r];
                    auto left = st.lower_bound(right - k);
                    if (left != st.end()) {
                        int cur = right - *left;
                        ans = max(ans, cur);
                    }
                    st.insert(right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

