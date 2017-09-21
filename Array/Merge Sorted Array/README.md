## Merge Sorted Array「LeetCode 88」

题目：合并两个已排序的数组。

```
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to 

hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
```

解题思路：

1. nums1 的长度为 m，nums2 的长度为 n，将两个已排序的数组合并，那么长度变为 m + n - 1
2. 对 nums1 和 nums2 进行从尾向前扫，先比较它们的最后一个元素的大小，把较大的那个插入到 m+n-1 的位置上，再依次向前推
3. 如果 nums1 中所有的元素都比 nums2 小，那么前 m 个还是 nums1 原来的内容，没有改变
4. 如果 nums1 中的数组比 nums2 大的，当 nums1 循环完了，nums2 中还有元素没加入 nums1，直接用个循环把 nums2 中所有的元素赋值到 nums1 剩下的位置

