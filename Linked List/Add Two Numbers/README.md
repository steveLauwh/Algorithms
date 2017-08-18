## Add Two Numbers 链表相加「LeetCode 2」

**题目要求：**

```
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
```

342 + 465 = 807， 个位是链表第一个节点。

给定两个非空链表(单链表)，表示两个非负整数，链表的每个节点都是用一位数字表示(0~9)，这些数字倒序存储在链表上，两个链表相加，
返回一个相加和倒序的链表。

两个非空链表长度可能不等。

**解决思路：**

1. 两个数分别倒序存储在两个单链表上，那么个位就是链表的第一个节点；
2. 为了方便返回一个相加和倒序的链表，借助哑节点 dummy；
3. 和 sum = (a + b + carry) % 10; 进位 carry = (a + b + carry) / 10；
4. 两个数倒序，返回的和也倒序，其实就是两个单链表对应节点的值两两相加，同时考虑每位进位；
5. 最高位两两相加，产生进位，需要新增一个节点，值为1。


