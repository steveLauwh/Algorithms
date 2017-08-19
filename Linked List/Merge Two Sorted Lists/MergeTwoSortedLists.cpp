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
        
        dummy.next = l1;
        
        ListNode *p = &dummy;
        
        while  (l1 && l2) {
            if (l1->val > l2->val) {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
                p->next = l1;
            }
            else {
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
