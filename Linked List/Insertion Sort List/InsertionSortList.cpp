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
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !(head->next)) {
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy; // cur 指向哑节点
        
        // 当前遍历的节点
        while (head) {
            ListNode *next = head->next;
            cur = dummy; // 每次比较当前遍历的节点，需要把 cur 重新指向哑节点，从头开始比较
            
            // 从头一个个比较
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            
            // 插入操作
            head->next = cur->next;
            cur->next = head;
            head = next;
        }
        
        return dummy->next;
    }
};
