## Maximum Depth of Binary Tree「LeetCode 104」

题目：求二叉树的最长深度。

```
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
```

解题思路：
方法一：递归思想

1. 从根节点开始，对其左子树的最长深度和右子树的最长深度进行比较，求出最长深度，然后加上根节点那层
2. 如何求出左子树的最长深度和右子树的最长深度，又进行递归

方法二：非递归思想，层序遍历二叉树(BFS)，然后计数总层数，借助 queue

1. 首选根节点入队列，判断当前队列是否为空
2. 不为空，那么层数加 1，循环操作，把队列的节点(一层上的节点)都出列，如果出列的节点有左右节点，就入队列
3. 每次判断当前队列是否为空，不为空就把层数加1

