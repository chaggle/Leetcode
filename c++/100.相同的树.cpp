/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        else if(p == nullptr || q  == nullptr)
            return false;//先判断有无节点数据，再判断节点数据是否相等，否则就为数据测试的逻辑错误。
        else if(p -> val != q -> val)
            return false;
        else 
            return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};
// @lc code=end

