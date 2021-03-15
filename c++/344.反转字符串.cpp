/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void recurrent(int start, int end, vector<char>& s)
    {
        if (start > end)
        {
            return;
        }
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        recurrent(start + 1, end -1, s);
        
    }

    void reverseString(vector<char>& s) {
        int n = s.size();
        recurrent(0, n-1, s);
    }
};
// @lc code=end

