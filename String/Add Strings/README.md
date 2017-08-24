## 两个字符串相加「LeetCode 415」

题目：两个字符串是由两个非负整数(每位由0~9)构成，求出两个字符串之和。

Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

题解：

* 两个字符串的长度可能不同，所以需要求出两个字符串长度；
* 两个字符串相加，字符串的末尾是个位，两个字符串从末尾向前两两相加；
* 相加考虑进位 carry；
* 虽然每个字符串中的每个字符是由 0~9 构成，但是要获取其值，需要 s[i]-'0'; 最后数字转换字符，需要 s[i]+'0';
* 注意循环判定条件；

