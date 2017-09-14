/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }
        
        // 一个节点
        if (!(head->next)) {
            return new TreeNode(head->val);
        }
        
        // 快慢指针找中间节点
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *frontEnd = head;  // 标记前半部分链表的尾部
        
        while (fast->next && fast->next->next) {
            frontEnd = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 后半部分链表的首部
        fast = slow->next;  // 此时 slow 为中间节点
        frontEnd->next = NULL; // 前半部分链表的尾部置NULL
        
        TreeNode *cur = new TreeNode(slow->val);
        
        if (head != slow) {
            cur->left = sortedListToBST(head);
        }
        
        cur->right = sortedListToBST(fast);
        
        return cur;
    }
};
