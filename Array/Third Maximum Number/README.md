## Third Maximum Number「LeetCode 414」

题目：求出一个数组中第三大的元素

```
Given a non-empty array of integers, return the third maximum number in this array. 

If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
```

解题思路：

方法一：

使用 set，插入操作是 O(logn)，遍历插入，时间复杂度 O(nlogn)。

1. 一维向量中元素有重复，首先遍历，插入到 set 中，去重复元素
2. 定义反向迭代器 set<int>::reverse_iterator，之后判断 set 中有多少个元素，小于三个就直接返回最大值，否则反向迭代就可以找到第三大的值

方法二：

用三个变量记录第一大，第二大，第三大的数，在遍历数据过程中更新这三个值。


