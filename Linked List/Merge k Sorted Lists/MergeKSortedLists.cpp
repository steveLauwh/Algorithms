// 方法一：没有递归，分冶法
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) {
            return NULL;
        }    
        
        int n = lists.size();
        
        // 巧妙，没有使用递归
        while (n > 1) {
            int k = (n + 1) / 2; // k 为累加
            
            for (int i = 0; i < n/2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            
            n = k;
        }
        
        return lists[0];
    }
    
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            
            cur = cur->next;
        }
        
        if (l1) {cur->next = l1;}
        
        if (l2) {cur->next = l2;}
        
        return dummy.next;
    }
};

// 方法二：partition 递归，分冶法
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) {
            return NULL;
        }
        
        return partition(lists, 0, lists.size() - 1);
    }
    
private:
    // partition 操作
    ListNode* partition(vector<ListNode*>& lists, int start, int end)  {
        // 递归，注意 partition 返回条件
        if (start == end) {
            return lists[start];
        }
        
        if (start < end) {
            int mid = start + (end - start) / 2;
            
            ListNode *front = partition(lists, start, mid);
            ListNode *last = partition(lists, mid + 1, end);
            
            return mergeTwoLists(front, last);
        }   
    }
    
    // 两个链表合并操作
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            
            cur = cur->next;
        }
        
        if (l1) {cur->next = l1;}
        
        if (l2) {cur->next = l2;}
        
        return dummy.next;
    }
};

// 方法三：利用堆
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) {
            return NULL;
        }
        
        ListNode dummy(-1);
        
        ListNode *node = &dummy;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        
        // 入堆
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                q.push(lists[i]);
        }
        
        // 出堆
        while (!q.empty()) {
            ListNode *p = q.top();
            q.pop();
            node->next = p;
            node = p;
            
            // 出来的链表，如果没有遍历完，把该链表的节点继续入堆
            if (p->next) {
                q.push(p->next);
            }
        }
        
        return dummy.next;
    }
    
private:
    struct cmp {
        bool operator ()(const ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};

