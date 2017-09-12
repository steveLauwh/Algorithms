## Swap Nodes in Pairs「LeetCode 24」

题目：对链表中，每相邻的两个节点进行交换，

```
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 

You may not modify the values in the list, only nodes itself can be changed.
```

解题思路：

1. 遍历一遍链表，时间复杂度为 O(n)
2. 借用哑节点 dummy，链表操作
