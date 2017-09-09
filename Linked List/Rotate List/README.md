## Rotate List 「LeetCode 61」

题目：旋转链表，将链表向右旋转 k 个位置，k 为非负数。

```
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
```

解题思路：

1. 考虑特殊情况，链表为空或者 k 为 0 时，直接返回该链表
2. 求链表的长度
2. k 并没有指定大小，所以很可能大于链表的长度，所以旋转 k 次，k = k % len
3. 首尾相连，遍历指针 cur 指向首部 head，就形成一个环
4. 遍历指针 cur 继续遍历 len - k 步，停止再断环，就可以达到要求
