## Valid Palindrome「LeetCode 125」

题目：判断字符串是否是有效回文，只考虑字母和数字，忽略大小写。

```
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
```

解题思路：

1. 由于只用考虑字母和数字，忽略其它字符，比如空格等
2. 两个碰撞指针，分别指向首尾，遍历整个字符串
3. 如果遇到非字母数字的字符就跳过，继续往下找，直到找到下一个字母数字或者结束遍历，如果遇到大写字母，就将其转为小写
4. 等左右指针都找到字母数字时，比较这两个字符，若相等，则继续比较下面两个分别找到的字母数字，若不相等，直接返回false

## Valid Palindrome II「LeetCode 680」

题目：在允许可以删除一个字符的情况下，判断该字符串是否为回文。

```c
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True

Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
```

解题思路：递归

1. 字符串只包含小写字符 a-z，方法类似 Valid Palindrome
2. 两个指针分别指向首尾，如果两头的字符不一致，则需要删除前者或者后者，完成删除后判断剩余字符串是否为回文。
