## Search a 2D Matrix「LeetCode 74」

```
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
```

解题思路：

1. 二维数组是有序的，用二分搜索法
2. 求二维数组的行和列
