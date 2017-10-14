## Convert Sorted Array to Binary Search Tree「LeetCode 108」

题目：把一个排序的数组转换成二叉搜索树

```
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
```

解题思路：

1. 二叉搜索树的特点是，根节点的值大于左子树节点的值，小于右子树节点的值
2. 由于有序的数组是从小到大存储，那么中间的元素作为二叉树的根
3. 从中间分开，分成左右两个有序数组，在分别找出其中间点作为原中间点的左右两个子节点
