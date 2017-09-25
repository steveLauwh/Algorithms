## Rotate Array「LeetCode 189」

题目：旋转数组，向右旋转 k 步

```
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
```

解题思路：三步

思路是先把前 n-k 个数字翻转一下，再把后 k 个数字翻转一下，最后再把整个数组翻转一下：

1 2 3 4 5 6 7 

4 3 2 1 5 6 7   (前 n-k 个数字翻转一下)

4 3 2 1 7 6 5   (把后 k 个数字翻转一下)

5 6 7 1 2 3 4   (把整个数组翻转一下)
