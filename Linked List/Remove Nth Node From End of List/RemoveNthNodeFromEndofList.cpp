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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return NULL;
        }
        
        if (!(head->next)) {
            if (n == 1) {
                return NULL;
            }
        }
 
        ListNode *pre = head;
        ListNode *cur = head;
        
        // cur 先走 n 步
        for (int i = 0; i < n; i++) {
            cur = cur->next;
        }
        
        // 说明链表的长度为n，要删除首元素
        if (!cur) {
            return head->next;
        }
        
        // 继续同时走
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        
        pre->next = pre->next->next;
        
        return head;
    }
};
