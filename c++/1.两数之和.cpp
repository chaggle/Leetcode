/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {  

public:
    // 第一种方法，此为最直接的想法，暴力求解，直接两次遍历
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for (i = 0; i < nums.size()-1; i++) {
            for(j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target)
                    return {i,j};
            }    
        }
        return {};
    }


    //第二种想法，hash直接映射的思想
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> hashtable;
       //c++中，map内部实现了一个红黑树，unordered_map内部
       //实现了一个哈希表
       for (int i = 0; i < nums.size(); ++i) {
          auto it = hashtable.find(target - nums[i]);
          //此处为自动递增一个it，用于查找target -nums[i]的值
          if (it != hashtable.end()) {
             return {it->second,i};
          }
        hashtable[nums[i]] = i;
       }     
       return {};
    }
};
// @lc code=end