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

## Intersection of Two Arrays II「LeetCode 350」

题目：求两个数组的交集，交集的结果出现多次，全部返回

```
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited 
such that you cannot load all elements into the memory at once?
```

解题思路：

1. 两个数组交集，可能出现多次的元素，使用 map 或 unordered_map 关联性容器实现
2. map<int, int> 第一个参数是数组的元素，第二个参数是数组元素出现个数
3. 把 nums1 先入 map 中，然后对 nums2 进行遍历，看 nums2 中每个元素在 map 中是否存在，如果存在，判断出现次数，依次存入到 vector 中
