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
        ListNode dummy(-1); // 哑节点，为返回链表的头
        
        int carry = 0;
        
        ListNode *node = &dummy;
        
        if (!l1 && !l2)
        {
            return NULL;
        }
       
        if (!l1)
        {
            return l2;
        }
        
        if (!l2)
        {
            return l1;
        }
        
        while (l1 != NULL || l2 != NULL)
        {
            int a, b;
            
            if (l1 != NULL)
            {
                a = l1->val;
                l1 = l1->next;
            }
            else
            {
                a = 0;
            }
            
            if (l2 != NULL)
            {
                b = l2->val;
                l2 = l2->next;
            }
            else
            {
                b = 0;
            }
            
            int sum = (a + b + carry) % 10;
            
            carry = (a + b + carry) / 10;
            
            node->next = new ListNode(sum);
            
            node = node->next;
        }
        
        if (carry > 0)
        {
            node->next = new ListNode(carry);
        }
        
        return dummy.next;
    }
};
