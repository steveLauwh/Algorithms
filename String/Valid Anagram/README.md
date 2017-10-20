## Valid Anagram「LeetCode 242」

题目：已知一个单词 s，给一个字符串 t，求 t 是否可以 d 颠倒组合成单词 s。

```
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
```

解题思路：

考虑特殊条件

方法一：

分别对字符串 s 和字符串 t，排序，然后比较是否相等，如果相等，说明 t 可以颠倒顺序成 s。

方法二：

1. 字符串 s 和 字符串 t 包含都是小写字母，字符串 t 经过颠倒能够成为字符串 s，说明字符串 s 和字符串 t 的包含的每个单词数是相等的
2. 用 unordered_map<char, int> 关联性容器，第一个参数表示单词，第二个参数表示单词在字符串中出现次数
3. 对字符串 s 遍历，单词出现就累加，对字符串 t 遍历，单词出现就累减
4. 如果两个字符串的组合单词完全相同，则最后 unordered_map 的第二个属性就等于 0

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        for (int i : count) {
            if (i) return false;
        }
        return true;
    }
};
```
