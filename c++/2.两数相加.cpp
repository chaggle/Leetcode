/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    //其中一种解法而已
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1; //记录l1长度
        int len2 = 1; //记录l2长度

        ListNode* p = l1;
        ListNode* q = l2;

        while(p -> next != NULL) //获取l1长度
        {
            len1++;
            p = p -> next;
        }

        while (q -> next != NULL) //获取l2长度
        {
            len2++;
            q = q -> next;
        }
        
        if(len1 > len2) //l1长，在l2末尾补零
        {
            for (int i = 1; i <= len1 - len2; i++)
            {
                q -> next = new ListNode(0);
                q = q->next;
            } 
        }
        else //l2长，在l1末尾补零
        {
            for (int i = 1; i <= len2-len1; i++)
            {
                p->next = new ListNode(0);
                p = p->next;
            } 
        } 
        p = l1;
        q = l2;
        bool count = false;   //进位标志
        ListNode* l3 = new ListNode(-1); //存放结果的链表，初始化值为-1；
        ListNode* w = l3;    //w为指向l3的节点指针
        int i = 0;  //相加结果
        while (p != NULL && q != NULL)
        {
            i = count + p->val + q->val;
            w->next = new ListNode(i%10);
            count=i>=10?true:false;
            w = w->next;
            p = p->next;
            q = q->next;
        }
        
        if (count)
        {
            w->next = new ListNode(1);
            w = w->next;  
        }
        return l3->next;
    }
};
// @lc code=end

