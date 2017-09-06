## Reverse Linked List「LeetCode 206」

题目要求：反转一个单链表，倒置链表。

1->2->3->4->5
     ||
5->4->3->2->1

```
Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

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
        
    }
};
```

解题思路：

递归和迭代两个版本。

迭代版本：

1. 使用三个指针，prev 初始指向空，cur 初始指向 head，next 初始指向 cur->next
2. 判断终止条件，cur 不为空，cur 一直向遍历到尾部
3. 从头节点开始，一个个节点进行反转

递归版本：

对于递归实现，首先反转从第二个结点到最后一个结点的链表，然后再将头结点放到已反转链表的最后，函数返回新链表的头结点。

## Reverse Linked List II「LeetCode 92」

题目：一个单链表，给定要倒序的起始位置，将起始位置进行倒序。

```
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
```
