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
    ListNode* sortList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        // 1. 一前一后指针，求出当前链表的中间链表
        while (p2 && p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        // 然后划分两部分
        p2 = p1->next;
        p1->next = NULL;
        
        return mergeTwoLists(sortList(head), sortList(p2));
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return NULL;
        }
        
        if (!l1) {
            return l2;
        }
        
        if (!l2) {
            return l1;
        }
        
        ListNode dummy(-1);
        dummy.next = l1; // 以 11 为主链表，将 l2 链表合并到 l1 上
        
        ListNode *p = &dummy;
        
        while(l1 && l2) {
            if (l1->val > l2->val) {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
                p->next = l1; // 插入到l1
            } else {
                p = l1;
                l1 = l1->next;
            }
        }
        
        if (l2) {
            p->next = l2;
        }
        
        return dummy.next;
    }
};
