/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    //split分割函数
    vector<string> split(string& preorder)
    {
        stringstream ss(preorder);
        string temp;
        vector<string> v;
        while (getline(ss, temp, ','))
        {
            v.push_back(temp);
        }
        return v;
    }
    bool isValidSerialization(string preorder) {
        vector<string> ss =  split(preorder);
        int n = ss.size();
        int in = 0, out = 0;
        for (int i = 0, m = 0; i < n; i++)
        {
            if (ss[i] != "#")
            {
                out += 2;
                m++;
            }
            if (i !=0 )
            {
                in++;
            }
            if (i != n - 1 && out <= in)
            {
                return false;
            }
            
        }
        return in == out;
    }
};
// @lc code=end

