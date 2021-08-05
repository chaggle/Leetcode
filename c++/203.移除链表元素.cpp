/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        /* 递归解法
        if (head == nullptr) return head;
        head -> next = removeElements(head -> next, val);
        return head -> val == val ? head -> next : head; */
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy, *cur = head;
        while(cur)
        {
            if(cur -> val == val)  
                pre -> next = cur -> next;
            else 
                pre = pre -> next; 
            cur = cur -> next;
        }
        return dummy -> next;
    }
};
// @lc code=end

