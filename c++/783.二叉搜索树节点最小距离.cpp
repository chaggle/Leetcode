/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    int minDiffInBST(TreeNode* root) {
        int pre = INT_MAX;
        int m = INT_MAX;
        return fun(root, m, pre);
    }

    int fun(TreeNode* root, int &m, int &pre)
    {
        if (!root) return m;
        fun(root -> left, m ,pre);
        m = min(m, abs(root -> val - pre));
        pre = root -> val;
        return fun(root -> right, m, pre);
    }
};
// @lc code=end

