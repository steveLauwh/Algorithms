## Odd Even Linked List 所有奇节点在前，偶节点在后「LeetCode 328」

题目：使链表的所有奇节点在前，偶节点在后

```
Given a singly linked list, group all odd nodes together followed by the even nodes. 

Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
```

解题思路：

1. 题目链表是按顺序，奇偶相连
2. 两个指针，一个指针 odd 指向奇节点，一个指针 even 指向偶节点，所有奇节点形成一个链表，所有偶节点形成一个链表
3. 注意在遍历前，需要保存偶节点的头节点，遍历完需要连接；最后把奇节点形成链表连接上偶节点形成链表
