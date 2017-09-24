## Sort Colors「LeetCode 75」

题目：对三种颜色(红、白、蓝)进行排序

```
Given an array with n objects colored red, white or blue, 

sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
```

解题思路：

可以用计数排序，因为只有三种颜色，可以新建一个数组 colors[3]，分别统计 0, 1, 2 的元素个数。时间复杂度为 O(n)，空间复杂度为 O(k)。

可以用三路快速排序法。对整个数组只遍历一遍，时间复杂度为 O(n)，空间复杂度为 O(1)。

1. 三路快排，注意临界条件
2. arr[0...zero] == 0，arr[zero+1...i-1] == 1，arr[two...n-1] == 2
3. 其中 i 一直向前探索，终止条件是，i < two
4. 注意 zero，two 的初值；zero = -1，two = nums.size();
