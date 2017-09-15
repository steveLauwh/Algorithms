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
    ListNode* plusOne(ListNode* head) {
        if (!head) {
            return NULL;
        }
        
        // 1. 旋转链表
        ListNode *rev = reverse(head);
        
        ListNode *prev = rev;
        ListNode *cur = rev;
        
        int carry = 1;
        
        while (cur) {
            pre = cur;  // 特别注意
            
            int sum = cur->val + carry;
            
            cur->val = sum % 10;
            carry = sum / 10;
            
            if (carry == 0)
                break;
            
            cur = cur->next;
        }
        
        if (carry) {
            pre->next = new ListNode(1);
        }
        
        return reverse(rev);
    }
 
private:
    ListNode* reverse(ListNode* head) {
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


// 可以利用栈结构，先进后出
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> s;
        ListNode *cur = head;
        
        while (cur) {
            s.push(cur);
            cur = cur->next;
        }
        
        int carry = 1;
        while (!s.empty() && carry) {
            ListNode *t = s.top(); 
            s.pop();
            int sum = t->val + carry;
            t->val = sum % 10;
            carry = sum / 10;
        }
        
        if (carry) {
            ListNode *new_head = new ListNode(1);
            new_head->next = head; // 有进位，插入头节点之前
            head = new_head;
        }
        
        return head;
    }
};
