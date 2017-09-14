## Copy List with Random Pointer「LeetCode 138」

题目：深拷贝一个链表，链表除了含有 next 指针外，还包含一个 random 指针，该指针指向字符串中的某个节点或者为空。

```
A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or null.

Return a deep copy of the list.
```

解题思路：两边遍历，时间复杂度为 O(n)，空间复杂度为 O(1)。

1. 第一个遍历，一个个复制节点，新链表和旧链表组成一个链表
2. 第二个遍历，旧链表有 random 指针指向，对新链表的节点也要做 random 指针指向
3. 新旧链表的拆分
