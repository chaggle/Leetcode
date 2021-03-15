/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    /*1.双指针原地修改。
    string removeDuplicates(string S) {
       int left = -1, right = 0;
       vector<bool> rec(S.size(), true);

       while (right < S.size())
       {
           if (left >= 0 && S[right] == S[left])
           {
               rec[right] = rec[left] =false;
               while (left >= 0 && !rec[left]) 
               {
                   -- left;
               }
               ++right;
           }else
           {
               left = right;
               ++right;
           }
       }
       string res;
       for (int i = 0; i < S.size(); ++i)
       {
           if (rec[i])
           {
               res.push_back(S[i]);
           }   
       }
       return res;
    }*/
    string removeDuplicates(string S) {
        string stk;
        for (char ch : S)
        {
            if (!stk.empty() && stk.back() == ch)
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};
// @lc code=end

