## Sort List

题目：使用常数级的空间复杂度，时间复杂度为 O(nlogn) 排序一个链表。

```
Sort a linked list in O(n log n) time using constant space complexity.
```

解题思路：

1. 排序算法时间复杂度为 O(nlogn)，可以使用归并排序、快速排序、堆排序实现
2. 此题使用归并排序求解，之前针对数组使用归并排序，空间复杂度 O(N)，需要复制出相等的空间来进行赋值归并。

归并排序：

1. 如何找出链表的中间点
2. 两部分递归
3. 最后进行合并操作

