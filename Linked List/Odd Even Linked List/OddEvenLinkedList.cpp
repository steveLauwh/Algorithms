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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return NULL;
        }
        
        if (!(head->next)) {
            return head;
        }
        
        ListNode *odd = head;  // 奇节点
        ListNode *even = head->next; // 偶节点
        
        // 保存偶节点的头节点，遍历完需要连接
        ListNode *temp = even;
        
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = temp;
        
        return head;
    }
};
