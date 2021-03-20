/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stk;
        int right = 0, left = 0;
        for(auto & token : tokens)
        {
            if (!isDigit(token))
            {
                right = *stk.rbegin();
                left = *(stk.rbegin() + 1);
                stk.pop_back();
                stk.pop_back();
                stk.push_back(getVal(right, left, token));
            }
            else
                stk.push_back(stoi(token));//stoi为字符串转变int型数
        }
        return *stk.rbegin();
    }

    bool isDigit(string& token)
    {
        return token != "+" && token != "-" && token != "*" && token != "/";
    }

    int getVal(int right, int left, string& token)
    {
        if(token == "+")
            return right + left;
            
        else if(token == "-")
            return  left - right;
            
        else if(token == "*")
            return right * left;

        else
            return left / right;
    }
};
// @lc code=end

