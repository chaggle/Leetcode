/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    /* //递归
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        recursion(root, res);
        return res;
    }

    void recursion(TreeNode* root, vector<int>& res)
    {
        if(root == NULL)
            return;
        recursion(root -> left, res);
        recursion(root -> right, res);
        res.push_back(root -> val);
    } */
       //迭代法
    
};
// @lc code=end

