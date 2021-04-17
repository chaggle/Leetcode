/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
private:
    int getId(long num, long w) {
        return num < 0 ? (num + 1) / w - 1 : num / w;
    }

public:
    //两种方法 ：1、set集合夹二分法； 2、桶排序 
    /* bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<long> st;
        for (int i = 0; i < n; i++) {
            auto lb = st.lower_bound((long)nums[i] - t); //lower_bound 函数为二分查找第一个大于目标数的位置。
            if (lb != st.end() && *lb <= (long)nums[i] + t) return true;
            st.insert(nums[i]);
            if (i >= k) st.erase(nums[i - k]);
        }
        return 0;
        //时间复杂度为nlogn
    } 2、以下为桶排序方法*/
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        unordered_map<long, long> ump;
        for (int i = 0; i < n; i++) {
            int id = getId(nums[i], (long)t + 1);
            if (ump.count(id))  return true;
            if (ump.count(id - 1) && nums[i] - ump[id - 1] <= t)    return true;
            if (ump.count(id + 1) && ump[id + 1] - nums[i] <= t)    return true;
            ump[id] = nums[i];
            if (i >= k) ump.erase(getId(nums[i - k], (long) t + 1));
        }
        return 0;
    }
};
// @lc code=end

