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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(-1);
        ListNode moreDummy(-1);
        
        ListNode *less = &lessDummy; // 小于 x 的链表
        ListNode *more = &moreDummy; // 大于或等于 x 的链表
        
        for (ListNode *cur = head; cur; cur = cur->next) {
            if (cur->val < x) {
                less->next = cur;
                less = cur;
            } else {
                more->next = cur;
                more = cur;
            }
        }
        
        less->next = moreDummy.next;
        more->next = NULL;
        
        return lessDummy.next;
    }
};
