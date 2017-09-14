## Merge k Sorted Lists「LeetCode 23」

题目：合并 k 个有序链表 (类似应用于分布式系统)

```
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
```

解题思路：

方法一：

分冶法，类似归并排序；对于 K 个有序链表，链表数目不断进行 partition 操作，然后将其 merge 操作(LeetCode 21 Merge Two Sorted Lists)。

将 K 个有序链表，递归划分

方法二：

