## Reverse Nodes in k-Group「LeetCode 25」

题目：每k个一组进行翻转

```
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
```

解题思路：分 k 组，局部翻转

1. 引入 dummy 哑节点，遍历，引入计数，当计数值等于 k，就局部翻转；否则继续遍历
2. 局部翻转操作

