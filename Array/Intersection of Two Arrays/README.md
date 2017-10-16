## Intersection of Two Arrays「LeetCode 349」

题目：求两个数组的交集

```
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
```

解题思路：时间复杂度 O(nlogn)，空间复杂度 O(n)

1. 题目要求是每个元素只能出现一次，出现的顺序可以是任意；结合这个条件，选用 set 关联性容器，该容器中的数据排好序，并且唯一
2. 第一步，将 nums1 数组的元素存储到 set1 中
3. 新建一个 set2 集合，对 nums2 中的所有元素遍历，再从 set1 查找 nums2 的元素是否已经存在，如果存在就插入到 set2 集合中。
