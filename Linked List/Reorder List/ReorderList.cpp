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
    void reorderList(ListNode* head) {
        if (!head || !(head->next) || !(head->next->next)) {
            return;
        }
               
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 1. 利用快慢指针，找出中间位置
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 需要把前半分的尾节点置 NULL
        ListNode *last = slow->next;
        
        slow->next = NULL;
        
        // 2. 中心位置的后半段进行旋转
        last = reverseList(last);
        
        // 3. 将后半段插入到前半段操作
        ListNode *prev = head;
        ListNode *cur = last;
        
        while (cur) {
            ListNode *node1 = prev->next;
            ListNode *node2 = cur->next;
            
            prev->next = cur;
            cur->next = node1;
            prev = node1;
            cur = node2;       
        }
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
