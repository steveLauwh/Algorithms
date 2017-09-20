## Valid Parentheses「LeetCode 20」

题目：给定一个字符串，只包含'(', ')', '{', '}', '[' and ']'；判断字符串中的括号匹配是否合法。

```
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 

determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
```

解题思路：栈顶元素反映了在嵌套的层次关系中，最近的需要匹配的元素。

使用栈。

1. 如果字符是 '{' 或 '(' 或 '['，就入栈
2. 如果该字符不是 '{' 或 '(' 或 '['，那么先获取栈顶元素，判断栈顶元素与当前字符的匹配字符是否相等。

