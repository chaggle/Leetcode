/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
//先写单链表，在写双向链表
class ListNode1{
    public:
        int val;
        ListNode1 *next;
        ListNode1(): val(-1), next(NULL){}
        ListNode1(int x): val(x), next(NULL){}
        ListNode1(int x, ListNode1 *p): val(x), next(p){}
        
};
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    ListNode1 *dummy;
    ListNode1 *tail;
    MyLinkedList(){
        dummy = new ListNode1(), tail = dummy;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0)
            return -1;
        ListNode1 *p = dummy;
        int i = -1;
        while(p){
            p = p->next; 
            ++i;
            if(i == index && p)
                return p->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode1 *p = new ListNode1(val, dummy->next);
        if(!dummy->next)
            tail = p;
        dummy->next = p;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode1 *p = new ListNode1(val);
        tail ->next = p;
        tail = tail->next;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode1 *p = dummy, *prev = p;
        int i = -1;
        if(index < 0){
            addAtHead(val);
        }
        while(p){
            prev = p;
            p = p->next;
            ++i;
            if(i == index && !p){
                addAtTail(val);
                return;
            }
            else if(i == index && p){
                ListNode1 *q = new ListNode1(val, p);
                prev->next = q;
                return;
            }
        }
        if(i < index){
            addAtTail(val);
        }

    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode1 *p = dummy, *prev = p;
        int i = -1;
        if(index < 0)
            return;
        while(p){
            prev = p;
            p = p->next;
            ++i;
            if(i == index && p){
                prev->next = p->next;
                if(p == tail)
                    tail = prev;
                delete p; 
                return;      
            }
        }
        if(i != index)
            return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

