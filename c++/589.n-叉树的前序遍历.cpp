/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
/*     //递归法求解
    void recursion(Node* root, vector<int>& res) {
        if (root == NULL)
            return;
        res.push_back(root -> val);    // 根
        for(auto i : root->children)   //自动迭代器
        {
            recursion(i,res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        recursion(root, res);
        return res;
    } */
       //迭代法求解
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        if (root != NULL)
        {
            stk.push(root);
        }
        while (stk.size())
        {
            Node* cur = stk.top();
            stk.pop();
            res.push_back(cur -> val);

            for (vector<Node*>::reverse_iterator itor = cur -> children.rbegin();
                itor != cur -> children.rend(); itor++)
            {
                stk.push(*itor);
            }
        }
        return res;        
    }
};
// @lc code=end

