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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        
        int lengthA = 0;
        int lengthB = 0;
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        while (pA) {
            lengthA++;
            pA = pA->next;
        }
        
        while (pB) {
            lengthB++;
            pB = pB->next;
        }
        
        if (lengthA <= lengthB) {
            pA = headA;
            pB = headB;
            
            int n = lengthB - lengthA;
            
            while(n) {
                pB = pB->next;
                n--;
            }
        } else {
            pA = headA;
            pB = headB;
            
            int n = lengthA - lengthB;
            
            while(n) {
                pA = pA->next;
                n--;
            }
        }
        
        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        
        return pA;
    }
};
