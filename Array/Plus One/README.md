## Plus One

题目：一个非负整数，存储在 vector 中，加 1 操作

```
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
```

解题思路：

1. 整数的最高位存储在一维向量的开头，最低位存储在一维向量的末尾，从最低位开始加 1
2. 在末尾数字加一，如果末尾数字是 9，那么则会有进位问题，而如果前面位上的数字仍为9，则需要继续向前进位
3. 首先判断最后一位是否为 9，若不是，直接加一返回，若是，则该位赋值为 0，再继续查前一位，同样的方法，直到查完第一位
4. 如果第一位原本为9，加一后会产生新的一位，那么最后要做的是，查运算完的第一位是否为 0，如果是，则在最前头加一个 1。
