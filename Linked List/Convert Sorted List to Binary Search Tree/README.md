## Convert Sorted List to Binary Search Tree「LeetCode 109」

题目：将有序链表转换为二叉搜索树。

```
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
```

解题思路：

1. 二分搜索树的特点，根节点的值大于左节点的值，小于右节点的值
2. 每次需要先找到中间节点，然后一分为二
3. 对于链表，使用快慢指针法，找出链表的中间节点
4. 找到中间节点，以中间节点的值建立一个二叉搜索树的根节点，然后把链表断开，分成前后两个链表，前链表尾部记得为NULL，都不包含链表的中间节点
5. 对前后两个链表继续递归
