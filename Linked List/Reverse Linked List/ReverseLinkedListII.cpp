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
    ListNode* reverseList(ListNode* head, int m, int n) {
        if (!head || !(head->next)) {
            return head;
        }
        
        ListNode dummy(-1);
        
        dummy.next = head;
        
        ListNode *head1 = &dummy;
        
        // 遍历完后，head1指向 m 位置的前一个节点
        for (int i = 1; i < m; i++) {
            head1 = head1->next;  
        }
        
        ListNode *prev = head1->next;  // prev 指向 m 位置
        
        ListNode *cur = prev->next;
        
        // 头插法
        for (int i = m; i < n; i++) {
            prev->next = cur->next;
            cur->next = head1->next;
            head1->next = cur;
            cur = prev->next;
        }
        
        return dummy.next;
    }
};
