## Remove Element「LeetCode 27」

题目：给定一个数组和值，将数组中与该值相等的元素全部删除，返回删除后的数组大小。

```
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
```

解题思路：与 LeetCode 283 题目做法类似，很简单。

1. 此题不能用额外的数组，所以只能原地做复制操作，遍历，当前的值与 val 比较，不等，复制，并且计数。
