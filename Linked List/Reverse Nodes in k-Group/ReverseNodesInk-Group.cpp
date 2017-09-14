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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }
        
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        ListNode *cur = head;
        dummy.next = head;
        
        int count = 0;
        
        while (cur) {
            ++count;
            
            if (count % k == 0) {
                prev = reverseGroup(prev, cur->next);
                cur = prev->next;
            } else {
                cur = cur->next;
            }
        }
        
        return dummy.next;
    }

private:
    ListNode* reverseGroup(ListNode* prev, ListNode* next) {
        ListNode *cur = prev->next;
        ListNode *curNext = cur->next;
        
        while (curNext != next) {
            cur->next = curNext->next;
            curNext->next = prev->next;
            prev->next = curNext;
            curNext = cur->next;
        }
        
        return cur;  // 局部反转后的最后一个节点
    }
};
