## 求整形数组中出现一次的元素「LeetCode 136」

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

题解：

在一个整形数组中，只有一个元素出现一次，其他元素都出现两次，找出只出现一次的元素，不能用额外的空间。

根据异或(XOR)特性，两个元素异或，相同为 0，不同为 1，与 0 异或得本身。

所以把整形数组中的所有元素进行异或，得出的结果就是只出现一次的元素。

