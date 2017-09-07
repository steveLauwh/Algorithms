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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return NULL;
        }
        
        ListNode dummy(-1);
        
        dummy.next = head;
        
        ListNode *prev = &dummy;
        ListNode *cur = head;
        
        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;
                delete cur;               
                cur = prev->next;
            } else {
                prev = prev->next;
                cur = cur->next;
            }
        }
        
        return dummy.next;
    }
};
