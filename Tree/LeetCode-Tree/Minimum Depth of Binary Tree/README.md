## Minimum Depth of Binary Tree「LeetCode 111」

题目：求二叉树的最小深度。

```
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
```

解题思路：递归思想

1. 与  Maximum Depth of Binary Tree 类似
2. 从根节点开始，当左子树为 NULL，需要求解右子树的最小深度
3. 当右子树为 NULL，需要求解左子树的最小深度
4. 当都不为 NULL，比较左子树和右子树的最小深度，求出最小深度后加 1
