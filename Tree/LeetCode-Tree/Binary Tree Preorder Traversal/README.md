## Binary Tree Preorder Traversal「LeetCode 144」

题目：二叉树的前序遍历

```
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
```

解题思路：

两种实现方式，递归和借助栈。

解法一：递归思想

1. 先访问根节点，再分别递归访问左子树，访问右子树。

解法二：迭代，借助栈

利用栈模拟递归实现。

1. 根节点先入栈，存储到向量 vector
2. 判断栈是否为空，不为空，判断入栈的节点是否有左子节点，如果有，入栈，存储到向量
3. 如果没有左子节点，说明根节点的左子树的左节点都入栈或判断完
4. 没有左子节点，出栈，判断出栈的节点是否有右子节点，有，把右子节点入栈和存储向量
