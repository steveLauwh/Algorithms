## Contains Duplicate「LeetCode 217」

题目：判断数组包含重复值

```
Given an array of integers, find if the array contains any duplicates. 

Your function should return true if any value appears at least twice in the array, 

and it should return false if every element is distinct.
```

解题思路:(简单)

1. 对整形的数组，查找数组中是否有重复的数
2. 使用 unordered_map 遍历数组，哈希表 key 具有唯一性，如果数组中有重复，比如一个元素先进入 unordered_map，再次遍历相同元素，就能在 unordered_map 找到

也可以用 unordered_set

还有一种方法，对整个数组进行排序，然后判断前后元素是否有相等。
