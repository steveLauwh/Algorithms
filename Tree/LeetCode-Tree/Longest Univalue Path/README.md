## Longest Univalue Path「LeetCode 687」

题目：求出最长路径的长度，最长路径中的每个节点都相等，最长路径不一定从根节点通过。两个节点之间的路径长度由它们之间的边数表示。

```
Given a binary tree, find the length of the longest path where each node in the path has the same value. 

This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
```

解题思路：递归思想

1. 对于根节点，先递归分别求出左右子树的最长路径长度
2. 如果根节点的值等于左子树节点的值或等于右子树节点的值，就在基础上加 1
3. 递归函数返回左右子树的最长路径长度
4. 特别注意，最长路径之和
