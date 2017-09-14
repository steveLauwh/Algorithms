## Merge k Sorted Lists「LeetCode 23」

题目：合并 k 个有序链表 (类似应用于分布式系统)

```
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
```

解题思路：

**假设总共有 k 个list，每个 list 的最大长度是 n，那么运行时间满足递推式 T(k) = 2T(k/2)+O(n`*`k)。根据主定理，可以算出算法的总复杂度是 O(nklogk)。**

方法一：

分冶法，自底向上不停的对半划分，比如 k 个链表先划分为合并两个 k/2 个链表的任务，再不停的往下划分，直到划分成只有一个或两个链表的任务，开始合并。

方法二：

分冶法，类似归并排序；对于 K 个有序链表，链表数目不断进行 partition 操作，然后将其 merge 操作(LeetCode 21 Merge Two Sorted Lists)。

将 K 个有序链表，递归划分。

方法三：方法妙

借助最小堆，C++ STL priority_queue(默认最大堆)

维护一个 k 个大小的最小堆，初始化堆中元素为每个链表的头结点，每次从堆中选择最小的元素加入到结果链表，再选择该最小元素所在链表的下一个节点加入到堆中。这样当堆为空时，所有链表的节点都已经加入了结果链表。元素加入堆中的复杂度为O（longk），总共有kn个元素加入堆中，因此，复杂度也是O（nklogk）

总时间复杂度是O(nklogk)。空间复杂度是堆的大小，即为O(k)。

