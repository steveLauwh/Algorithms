/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 迭代版
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        
        ListNode *prev = head;
        ListNode *cur = head->next;
        
        for (; cur; cur = prev->next) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
                delete cur;
            } else {
                prev = cur;
            }
        }
        
        return head;
    }
};

// 递归版
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        
        ListNode dummy(-1);
        
        dummy.next = head;
        
        recursion(head, head->next);
        
        return dummy.next;
    }

private:
    static void recursion(ListNode* prev, ListNode* cur) {
        if (!cur) {
            return;
        }
        
        if (prev->val == cur->val) {
            prev->next = cur->next;
            delete cur;
            recursion(prev, prev->next);
        } else {
            recursion(prev->next, cur->next);
        }
    } 
};
