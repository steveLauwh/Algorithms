## 从尾部开始删第 n 个节点 Remove Nth Node From End of List「LeetCode 19」

题目：只允许一次遍历, 对一个链表，从尾部开始数，删掉第 n 个节点。

```
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
```

解题思路：

1. 情况一：链表长度为2，n = 2，需要删除首元素
2. 由于只允许一次遍历，所以不能用一次完整的遍历来统计链表中元素的个数
3. 双指针法，prev，cur 指针分别指向链表头部，首先 cur 先走 n 步，如果此时 cur 指向为空，那么删除的是首元素
4. 如果 cur 不指向空，那么此时 cur 和 prev 同时走，当 cur 走完，那么 prev 指向要删除节点的前一个节点
5. 然后进行删除操作
