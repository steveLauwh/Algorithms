## Intersection of Two Linked Lists「LeetCode 160」

题目：找出两个单链表的第一个交集点。找到交互点，需要保持原有的结构返回。

```
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
```

解题思路：

1. 理解题目，两个链表，不构成环，并且长度不一定相等，如果两个链表有交集点，那么交集点之后的所有节点都是两个链表共有的
2. 链表 A 的长度为 lengthA，链表 B 的长度为 lengthB
3. 以尾部对齐，如果两个链表长度不相等，那么可以先让长度长的链表从头节点先走 abs(lengthA - lengthB) 步，这样两个链表的指针就可以对齐
4. 最后长度短的从起始开始走，长度长的继续向前走，这样，节点值相等就为交集点
