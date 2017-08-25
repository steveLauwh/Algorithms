## 旋转字符串 Reverse String I「LeetCode 344」

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

题解：

将一个字符串进行倒序输出。

其实就是首尾字符进行两两交换，第二个与倒数第二个进行两两交换，终止条件为中间字符。

## 旋转字符串 Reverse String II「LeetCode 541」

题目：

```
Given a string and an integer k, 
you need to reverse the first k characters for every 2k characters counting from the start of the string.
If there are less than k characters left, reverse all of them. 
If there are less than 2k but greater than or equal to k characters, 
then reverse the first k characters and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
```

题解：

给定一个字符串和一个整形 k，从字符串开始，每 2k 个字符，旋转前 k 个字符；当字符串不足 k 个字符，就全部旋转；当字符串小于 2k 个字符，但是大于 k 个字符，就只旋转前 k 个字符。

C++ STL：旋转 `reverse   [first, last)`

每 2k 个字符进行遍历，`[i, i+k)`区间旋转，但是考虑到不足 2k 个字符就旋转前 k 个字符，所以翻转尾位置 `i+k 和 end()` 进行比较，每次取小者。
