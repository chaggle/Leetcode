/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /* 第一种比较简单的想法，两层枚举法，暴力解决问题！
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        for (ListNode* p = headA; p != nullptr; p = p -> next)
        { 
            for (ListNode* q = headB; q != nullptr; q = q -> next)
            {
                if(q == p)  return p;
            }
        }
        return nullptr;
    }
    第二种想法，使用栈比较，能用STL中的stack本身，也能用vector实现
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> s1, s2;
        while (headA)
        {
            s1.push(headA);
            headA = headA -> next;
        }

        while (headB)
        {
            s2.push(headB);
            headB = headB -> next;
        }

        ListNode* ans = NULL;

        while (!s1.empty() && !s2.empty() && s1.top() == s2.top())
        {
            ans = s1.top();
            s1.pop();
            s2.pop();
        }
        return ans;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode *> s1, s2;
        while (headA)
        {
            s1.push_back(headA);
            headA = headA -> next;
        }

        while (headB)
        {
            s2.push_back(headB);
            headB = headB -> next;
        }

        ListNode* ans = NULL;

        while (!s1.empty() && !s2.empty() && s1.back() == s2.back())
        {
            ans = s1.back();
            s1.pop_back();
            s2.pop_back();
        }
        return ans;
    }
    第三种想法，哈希想法！*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode* temp = headA;
        while (temp != nullptr)
        {
            visited.insert(temp);
            temp = temp -> next;
        }
        temp = headB;
        while (temp != nullptr)
        {
            if (visited.count(temp)) return temp;
            temp = temp -> next;
            
        }
        return nullptr;
    }
};
// @lc code=end

