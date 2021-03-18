/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    /* ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode -> next = head;
        ListNode* pre = dummyNode;
        for (int i = 0; i < left - 1; i++)
        {
            pre = pre -> next;
        }

        ListNode* cur = pre -> next;

        ListNode* next;
        
        for (int i = 0; i < right - left; i++)
        {
            next = cur -> next;
            cur -> next = next -> next;
            next -> next = pre -> next;
            pre -> next = next;
        }
        return dummyNode -> next;
    } */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode* heads = dummy;
        right -= left;
        while (left-- > 1)
        {
            heads = heads -> next;
        }
        
        ListNode* pre = heads -> next, *cur = pre -> next;
        while (right-- > 0)
        {
            ListNode* tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }
        heads -> next -> next = cur;
        heads -> next = pre;
        return dummy -> next;
    }
};
// @lc code=end

