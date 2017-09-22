## Two Sum「LeetCode 1」

题目：给定一个整形数组和 target 值，找出数组中两个元素的和等于 target，返回该数组元素对应的索引。

```
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

解题思路：

1. 先遍历一遍数组，建立 map 数据，map<int, int>，key 表示数组元素的值，value 表示数组元素值的索引
2. 再遍历一遍，开始查找 target - nums[i]，在不在 map 数据中(使用 map 的 count 方法)
