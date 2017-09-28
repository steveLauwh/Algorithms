## Balanced Binary Tree「LeetCode 110」

题目：判断一个二叉树是否是平衡二叉树

```
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 

in which the depth of the two subtrees of every node never differ by more than 1.
```

解题思路：递归思想

方法一：

1. 平衡二叉树的左右子树的高度相差不超过 1
2. 使用递归实现求各个节点深度的函数
3. 以根节点为起点，先比较其左右子树的深度差
4. 继续递归判断节点的左右子树是否平衡

方法二：(优化)

1. 方法一是求出每个节点深度，现在方法二是发现子树不平衡，则不计算具体的深度，而是直接返回-1
2. 对于每一个节点，我们通过 checkDepth 方法递归获得左右子树的深度，如果子树是平衡的，则返回真实的深度，若不平衡，直接返回-1
