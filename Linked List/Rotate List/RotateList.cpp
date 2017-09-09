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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !(head->next) || k == 0) {
            return head;
        }
        
        ListNode *cur = head;
        
        int len = 1;
        
        // 求出链表的长度
        while (cur->next) {
            ++len;
            cur = cur->next;
        }
        
        k = k % len;
        
        // 首尾相连
        cur->next = head;
        
        // 继续遍历 len - k 步
        for (int i = 0; i < len - k; i++) {
            cur = cur->next;
        }
        
        // 断环操作，先获取链表的头节点
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};
