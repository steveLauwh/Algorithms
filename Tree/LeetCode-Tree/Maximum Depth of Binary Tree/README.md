## Maximum Depth of Binary Tree「LeetCode 104」

题目：求二叉树的最长深度。

```
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
```

解题思路：递归思想

1. 从根节点开始，对其左子树的最长深度和右子树的最长深度进行比较，求出最长深度，然后加上根节点那层
2. 如何求出左子树的最长深度和右子树的最长深度，又进行递归

