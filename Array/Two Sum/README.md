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
2. 再遍历一遍，i 从 0 开始遍历，查找 target - nums[i] 在不在 map 数据中(使用 map 的 count 方法)


map 和 set 两种容器的底层结构都是红黑树，所以容器中不会出现相同的元素；
* count() 方法的结果只能为 0 和 1，可以以此来判断键值元素是否存在，1 表示有这个元素，0 表示没有这个元素
* find() 方法返回值是一个迭代器，成功返回迭代器指向要查找的元素，失败返回的迭代器指向end

## Two Sum II - Input array is sorted 「LeetCode 167」

题目：数组已排好序，比 Two Sum 题目要简单

```
Given an array of integers that is already sorted in ascending order, 

find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
```

解题思路：

1. 数组已经排好序，两个索引分别指向一头一尾，进行碰撞
2. 如果两个索引指向的值相加等于 target，就对索引分别加 1，并返回
3. 否则，如果和大于 target，那么尾索引针向前进，如果和小于 target，那么头索引向前进
