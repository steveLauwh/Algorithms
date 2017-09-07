## Remove Linked List Elements「LeetCode 203」

题目：给定一个值，删除链表中所有等于该值的节点。

```
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
```
```
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
    ListNode* removeElements(ListNode* head, int val) {
        
    }
};
```

解题思路：

1. 涉及到删除节点的题目，利用哑节点 dummy
2. 一前一后指针，遍历，当节点的值与给定的值相等，就做删除操作；否则一前一后指针，都前进一步。
