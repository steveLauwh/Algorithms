## Binary Tree Inorder Traversal「LeetCode 94」

题目：二叉树的中序遍历

```
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
```

解题思路：

递归思想:

算法的时间复杂度是 O(n), 而空间复杂度则是递归栈的大小，即O(logn)。

1. 比较简单，先访问左边，再访问根节点，最后访问右边节点。

非递归思想

使用栈来实现迭代。

1. 从根节点开始，先将根节点压入栈，然后再将其所有左子结点压入栈，直到左子树节点为空
2. 然后取出栈顶节点，保存节点值，再将当前指针移到其右子节点上，若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中。

这样就保证了访问顺序为 左-根-右。
