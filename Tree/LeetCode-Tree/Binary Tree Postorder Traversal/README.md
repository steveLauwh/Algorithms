## Binary Tree Postorder Traversal「LeetCode 145」

题目：二叉树的后序遍历

```
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
```

解题思路：

递归思想

1. 先访问左子树节点，再访问右子树节点，后访问根节点。

迭代思想

