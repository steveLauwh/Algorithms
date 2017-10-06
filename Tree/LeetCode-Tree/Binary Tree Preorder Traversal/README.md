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

解法二：借助栈

利用栈模拟递归实现。

1. 根节点先入栈，再循环判断，栈是否为空，不为空，栈顶的元素出栈
2. 如果出栈的元素有左右子树，先把右子树先入栈，再把左子树入栈。
