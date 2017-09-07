## Palindrome Linked List「LeetCode 234」

题目：判断单链表是不是回文，要求 O(n) 的时间复杂度和 O(1) 的空间复杂度。

```
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
```

解题思路：

方法一：

遍历整个链表，将链表每个节点的值记录在数组中，再判断数组是不是一个回文数组，时间复杂度为 O(n)，但空间复杂度也为 O(n)，不满足空间复杂度要求。

方法二：

利用栈先进后出的性质，将链表前半段压入栈中，再逐个弹出与链表后半段比较。时间复杂度 O(n)，但仍然需要 n/2 的栈空间，空间复杂度为 O(n)。

方法三：

反转链表法，将链表后半段原地翻转，再将前半段、后半段依次比较，判断是否相等，时间复杂度 O（n），空间复杂度为 O(1)满足题目要求。

链表翻转可以参考 [Reverse Linked List](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Linked%20List/Reverse%20Linked%20List) 的代码。

对于反转链表法：

1. 如何找到链表的中心位置，注意链表长度的奇偶性，使用快慢指针法
2. 找到链表中心位置，将链表的后半段进行翻转操作
3. 前半段和后半段一一比较
