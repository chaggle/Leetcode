/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    /* int strStr(string haystack, string needle) {
        //BF朴素算法。
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++) {
            int j = i, k = 0;
            while (k < m && haystack[j] == needle[k]) {
                j++;
                k++;
            }
            if(k == m) return i;
        }
        return -1;
    } */
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if (m == 0) return 0;
        //设置哨兵
        s.insert(s.begin(), ' ');
        p.insert(p.begin(), ' ');
        vector<int> next(m + 1);
        //预处理next数组
         
    }
};
// @lc code=end

