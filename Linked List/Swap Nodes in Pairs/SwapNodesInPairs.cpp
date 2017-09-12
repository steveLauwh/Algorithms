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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return NULL;
        }
        
        if (!(head->next)) {
            return head;
        }
        
        ListNode dummy(-1);
        
        dummy.next = head;
        
        ListNode *pre = &dummy;
        ListNode *cur = head;
        
        // 链表操作
        while (cur && cur->next) {
            ListNode *nextNode = cur->next;
            
            cur->next = nextNode->next;
            nextNode->next = cur;
            pre->next = nextNode;
            
            pre = cur;
            cur = cur->next;
        }
        
        return dummy.next;
    }
};
