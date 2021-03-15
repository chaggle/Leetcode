/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    // 1.暴力AC法
  /*  int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, temp = 0 ;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                if(temp <= count)
                    temp = count;
                count = 0;
            }
        }
        if(temp <= count)
            return count;
        else
            return temp;        
    }   
};//时间：O(n), 空间：O(1)*/
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int index = -1, max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                index = i;
            }
            else
            {
                if(max <= i - index)
                {
                    max = i - index; 
                }
            }
        }
        return max;
    }
};

// @lc code=end

