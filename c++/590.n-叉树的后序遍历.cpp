/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>res;
        recursion(root,res);
        return res;
    }

    void recursion(Node* root, vector<int>& res)
    {
        if (root == NULL)
            return;
        for (auto i : root -> children)
        {
            recursion(i, res);
        }        
        res.push_back(root -> val);
    }
};
// @lc code=end

