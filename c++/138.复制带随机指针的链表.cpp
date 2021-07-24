/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //的确看其他人的代码能学到很多有用的东西！
    /* Node* copyRandomList(Node* head) {
         if(head == nullptr) {
            return nullptr;
        }

        Node* ans = new Node(-1), *temp = ans, *x, *y;
        unordered_map<Node*, Node*> node_map;

         building list. 
        for(x = head; x; x = x->next) {
            node_map[x] = temp = temp->next = new Node(x->val);
            此处为三句话缩成一句话！的确精简！但是不易读懂！还是正常使用将其作为三句话的改写较好！
            改写如下！
            temp -> next = new Node(x-> val);
            temp = temp -> next;
            hash[x] = temp;
            应该是哈希表的拉链法！
        }

         building random-pointer of list. 
        for(x = head, y = ans->next; x; x = x->next, y = y->next) {
            y->random = node_map[x->random];
        }

        return ans->next;
    } */
};
// @lc code=end

