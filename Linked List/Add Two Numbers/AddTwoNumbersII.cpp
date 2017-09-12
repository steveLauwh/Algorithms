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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
        
        ListNode *node = &dummy; // 新链表-sum
        
        int carry = 0;
        
        // 1. 反转两个链表
        l1 = reverseList(l1);
        
        l2 = reverseList(l2);
        
        // 2. 链表相加操作
        while (l1 || l2) {
            int a, b;
            
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            } else {
                a = 0;
            }
            
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            } else {
                b = 0;
            }
            
            int sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            
            node->next = new ListNode(sum);
            node = node->next;
        }
        
        if (carry > 0) {
            node->next = new ListNode(carry);
        }
        
        // 3. 最后再反转相加结果的链表
        dummy.next = reverseList(dummy.next);
        
        return dummy.next;
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return NULL;
        }
    
        if (!(head->next)) {
            return head;
        }
    
        ListNode *prev = NULL;
        ListNode *cur = head;
    
        while (cur) {
            ListNode *nextNode = cur->next;
            
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        
        return prev;
    }
};
