/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 迭代版本
class Solution {
public:
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

// 递归版本
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return ret;
    }
};
