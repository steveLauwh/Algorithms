## Search Insert Position「LeetCode 35」

题目：查找插入的位置，一个排序的数组，给定一个目标值，如果有目标值，返回索引，没有，返回插入到数组中的索引

```
Given a sorted array and a target value, return the index if the target is found.

If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
```

解题思路：

方法一：

1. 只需要遍历一遍原数组，若当前数字大于或等于目标值，则返回当前坐标，如果遍历结束了，说明目标值比数组中任何一个数都要大，则返回数组长度n即可

方法二：

1. 二分搜索法，必须完整正确写出，考虑异常情况

