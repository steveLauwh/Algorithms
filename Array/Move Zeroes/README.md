## Move Zeroes「LeetCode 283」

题目：给定一个数组，写一个函数，将数组中所有的 0 移到数组的末尾，维持其它所有非 0 元素的相对位置。

```
Given an array nums, write a function to move all 0's to the end of it while maintaining
the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
```

解题思路：

1. 题目要求是将所有非 0 元素移到前面，并且它们相对位置不变，可以设置一个变量 j， 从 0 开始，将非 0 元素一个个赋值以 j 为索引的原有数组
2. 以给定数组大小为判断条件，继续将 0 元素复制到原有数组中
