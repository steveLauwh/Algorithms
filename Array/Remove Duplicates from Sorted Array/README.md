## Remove Duplicates from Sorted Array「LeetCode 26」

题目：给定一个排序好的数组，删除数组中重复的数，每个数只出现一次，返回数组的大小。

```
Given a sorted array, remove the duplicates in place 

such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the new length.
```

解题思路：

1. 不能使用额外的空间，原地复制，与 LeetCode 283 或 LeetCode 27 方法类似
2. 前后元素进行比较，设一个变量，`int index = 0;`，从第2个元素(`int i = 1`)开始遍历，按照条件，前面一个元素与后面一个元素比较，
   如果不等，那么原地赋值操作(注意地方)；
3. 否则，前后两个元素相等，继续遍历
