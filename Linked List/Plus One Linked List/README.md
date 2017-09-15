## Plus One Linked List「LeetCode 369」

题目：链表加1

```
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
```

解题思路：

此题从链表末尾加1，考虑进位，最容易想到的先把链表反转，再加1，然后求出结果，再把链表反转。

1. 反转链表
2. 循环遍历，从链表首元素开始加1，考虑进位
3. 再反转链表
