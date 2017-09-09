## Partition List 「LeetCode 86」

题目：链表划分，给定一个链表和值 x，对其进行分区，使小于 x 的所有节点，都在大于或等于 x 前面，同时保留原有的顺序。

```
Given a linked list and a value x, 

partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
```

解题思路：

1. 链表划分，一边的所有节点小于某值，另一边的所有节点都大于等于某值，可以使用两个指针，初始分别指向两个哑节点 dummy
2. 对链表遍历，指针 A 负责串联小于某值，指针 B 负责串联大于等于某值
3. 然后将指针 A 串联的链表，连接指针 B 串联的链表，这样就实现链表的划分(Partition)操作。
