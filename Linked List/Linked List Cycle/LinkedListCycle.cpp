/**
 * Given a linked list, determine if it has a cycle in it.
 * return the node where the cycle begins. If there is no cycle, return NULL.
 * Follow up:
 * Can you solve it without using extra space?
 * 
 */
 
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
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
     
        ListNode *slow = head;
        ListNode *fast = head->next;  
     
        while (fast && fast->next) {
            if (slow == fast) {
                return true;
            }
         
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
 
    ListNode* detectCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }
     
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 1. 找到相遇点
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
         
            if (slow == fast) {
                break;
            }          
        }
     
        if (!fast || !fast->next) {
            return NULL;
        }
     
        // 2. slow 指向起始点
        slow = head;
     
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
