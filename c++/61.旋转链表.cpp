/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        int tot = 0;
        auto tmp = head;
        while (tmp != nullptr && ++tot > 0) tmp = tmp->next;
        k %= tot;
        if (k == 0) return head;

        // 使用「快慢指针」找到倒数第 k 个节点（新头结点）：slow 会停在「新头结点」的「前一位」，也就是「新尾结点」
        auto slow = head, fast = head;
        while (k-- > 0) fast = fast->next;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        // 保存新头结点，并将新尾结点的 next 指针置空
        auto nHead = slow->next;
        slow->next = nullptr;
        // 将新链表的前半部分（原链表的后半部分）与原链表的头结点链接上
        fast->next = head;
        return nHead;
    }
};
// @lc code=end

