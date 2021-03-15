/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    void replace(string& s)
    {
        int pos = s.find(" ");
        while (pos != -1) 
        {
            s.replace(pos, 1, "");
            pos = s.find(" ");
        }
        pos = s.find("(-");
        while(pos != -1)
        {
            s.replace(pos, 2, "(0-");
            pos = s.find("(-");
        }
    }
    int calculate(string s) 
    {
        // 存放所有的数字
        stack<int> nums;
        // 为了防止第一个数为负数，先往 nums 加个 0
        nums.push(0);
        // 将所有的空格去掉，并将 (- 替换为 (0-
        replace(s);
        // 存放所有的操作，包括 +/-
        stack<char> ops;
        int n = s.size();
        for(int i = 0; i < n; i++) 
        {
            char c = s[i];
            if(c == '(')
                ops.push(c);
            else if(c == ')') 
            {
                // 计算到最近一个左括号为止
                while(!ops.empty()) 
                {
                    char op = ops.top();
                    if(op != '(')
                        calc(nums, ops);
                    else {
                        ops.pop();
                        break;
                    }
                }
            }
            else {
                if(isdigit(c)) 
                {
                    int cur_num = 0;
                    int j = i;
                    // 将从 i 位置开始后面的连续数字整体取出，加入 nums
                    while(j <n && isdigit(s[j]))
                        cur_num = cur_num*10 + (s[j++] - '0');
                    // 注意上面的计算一定要有括号，否则有可能会溢出
                    nums.push(cur_num);
                    i = j-1;
                }
                // c == '+' || c == '-'
                else 
                {
                    // 有一个新操作要入栈时，先把栈内可以算的都算了
                    while(!ops.empty() && ops.top() != '(')
                        calc(nums, ops);
                    ops.push(c);
                }
            }
        }
        while(!ops.empty())
            calc(nums, ops);
        return nums.top();
    }
    void calc(stack<int> &nums, stack<char> &ops) 
    {
        if(nums.size() < 2 || ops.empty())
            return;
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(op == '+' ? a+b : a-b);
    }
};
// @lc code=end

