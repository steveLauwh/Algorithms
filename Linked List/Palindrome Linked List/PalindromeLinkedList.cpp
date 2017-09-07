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
    bool isPalindrome(ListNode* head) {
        if (!head || !(head->next)) {
            return true;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 1. 找到中心位置，注意链表长度的奇偶性       
        while (slow != NULL && fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            
            if (fast != NULL) {
                fast = fast->next;    
            }
        }
        
        // 2. 中心位置的后半段进行旋转      
        slow = reverseList(slow);
        
        // 3. 前后半段一一比较
        while (slow) {
            if (slow->val != head->val) {
                return false;
            }
            
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) {
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
