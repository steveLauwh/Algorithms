## Reverse Integer

```
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
```

解题思路：

1. 对 32 位有符号的整形，进行翻转，翻转的值定义 64 位，防止翻转后的值溢出

2. 求余，获得个位

3. 求商，获得新的数

