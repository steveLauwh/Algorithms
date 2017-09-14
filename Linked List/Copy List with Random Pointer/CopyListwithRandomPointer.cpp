/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) { return NULL;}
        
        // 新增链表的每个节点
        for (RandomListNode *cur = head; cur; ) {
            RandomListNode *node = new RandomListNode(cur->label);
            
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        
        // 对新增链表的每个节点，进行 random
        for (RandomListNode *cur = head; cur; ) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            
            cur = cur->next->next;
        }
        
        // 拆分新旧链表，返回新链表
        RandomListNode dummy(-1);
        RandomListNode *newCur = &dummy;
        RandomListNode *cur = head;
        
        while (cur) {
            newCur->next = cur->next;
            cur->next = cur->next->next;
            newCur = newCur->next;
            cur = cur->next;
        }
        
        return dummy.next;
    }
};
