## Implement strStr()「LeetCode 28」

题目：实现 strStr(string str1, string str2)函数，

功能：从字符串 str1 中查找是否有字符串 str2， 如果有，从 str1 中的 str2 位置起，返回 str1 的指针，如果没有，返回 null。

```
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
```

实现strstr(). 返回 needle(关键字) 在 haystack(字符串) 中第一次出现的位置，如果 needle 不在 haystack 中，则返回 -1。 

注：strstr() 是 c++ 中的一个函数

解题思路：

暴力解法 和 KMP 算法

字符串匹配问题

1. 字符串 str1 的长度为 m，字符串 str2 的长度为 n
2. 从 str1 从匹配 str2，如果匹配，返回 str2 在 str1 的第一次出现位置，暴力解法，双 for 循环，第一层 for 循环的终止条件小于等于 m - n；并不需要
整个 str1 都遍历完
3. 第二层循环，遍历 一遍 str2 字符串，str1 和 str2 的一个个字符对应比较，如果对应位置有不等的，则跳出循环，如果一直都没有跳出循环，则说明子字符串出现了，则返回起始位置即可
