/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
  /*1.自己的相关的想法，暴力AC
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                for (int j = i; j < nums.size()-1; j++)
                {
                    if(nums[j+1] != 0)
                    nums[j] = nums[j + 1];
                }
                nums[nums.size()-1] = 0;
            }
            if(count != 0)
                count--;
            else
                break;
        }
    }
*/
    //第二种想法，两次遍历。
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
                nums[count++] = nums[i];
        }
        for(int i = count;i<nums.size();++i) {
			nums[i] = 0;
		}
    }

    //第三种， 一次遍历，暂时不好做笔记，先学习，回去在想思路与题解

};
// @lc code=end

