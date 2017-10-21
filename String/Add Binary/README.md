## Add Binary「LeetCode 67」

题目：两个字符串由二进制表示，求出和，也是由二进制表示

```
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
```

解题思路：

考虑情况：

* 两个字符串可能不相等
* 考虑进位 carry
* 从两个字符串的末位开始，一一相加，字符串取出的是字符，需要转换数字；无法取出，按 0 处理
* 最后相加完，还要判断 carry 是否有进位

1. 对两个字符串遍历，从末位开始，每次取出一个字符，转为数字，相加
2. 相加和对 2 求余，为结果，对 2 求商，为进位
3. 最后还要判断下 carry，如果为 1 的话，要在结果最前面加上一个 1
