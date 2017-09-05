/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 递归版本
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }    
        
        ListNode *nextNode = head->next; // 遍历的节点
        
        if (head->val == nextNode->val) {
            while (nextNode && head->val == nextNode->val) {
                ListNode *temp = nextNode;
                nextNode = nextNode->next;
                delete temp;
            }
            
            delete head;  // 删除重复的最后一个节点
            return deleteDuplicates(nextNode);
        } else {
            head->next = deleteDuplicates(head->next);            
            return head;
        }
    }
};

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }    
        
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *prev = &dummy;
        
        ListNode *cur = head;
        
        while (cur) {            
            bool flag = false;
            
            while (cur->next && cur->val == cur->next->val) {
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
                flag = true;
            }
            
            if (flag) {  // flag 为 true，重复节点还有最后一个节点，这里没有用 delete 删除，而是调过
                prev->next = cur->next; 
            } else {
                prev = prev->next;
            }
            
            if (cur) { // 巧妙之处
                cur = cur->next;
            }
        }
        
        return dummy.next;
    }
};
