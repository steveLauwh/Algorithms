## Maximum Subarray「LeetCode 53」

题目：最大的子数组的和

```
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, 
which is more subtle.
```

方法一：遍历，时间复杂度为 O(n)

1. 定义两个变量，一个存储返回值 ret，即最大的子数组的和，另一个变量为当前累加最大的值 curSum
2. 每遍历一个数字 number，比较 curSum + number 和 number 中的较大值存入 curSum
3. 然后再把 ret 和 curSum 中的较大值存入 ret

方法二：分冶法，时间复杂度为 O(nlogn)

这个分治法的思想就类似于二分搜索法

1. 把数组一分为二，分别找出左边和右边的最大子数组之和
2. 然后从中间开始向左右分别扫描，求出的最大值分别和左右两边得出的最大值相比较取最大的那一个
