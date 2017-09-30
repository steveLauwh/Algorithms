## Path Sum「LeetCode 112」

题目：已知一个二叉树和 sum，找出从根节点到叶子节点的路径，其路径上的所有节点和为 sum。

```
Given a binary tree and a sum, determine if the tree has a root-to-leaf path

such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
```

解题思路：递归思想

1. 递归终止条件：如果当前节点是空的，则返回false；如果是叶子节点，那么如果剩余的 sum 等于当前叶子的值，则找到满足条件的路径，返回true
2. 递归条件是看左子树或者右子树有没有满足条件的路径，也就是子树路径和等于当前 sum 减去当前节点的值。

## Path Sum II「LeetCode 113」

题目：相对 Path Sum，此题路径不只一条，找出所有从根节点到叶子节点的路径。

```
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
```

解题思路：DFS

1. 解题方法与 Path Sum 相同，只不过返回二维数组，保存所有路径
2. 使用一维 vector 作为中间者，用来保存查找的一条路径的节点，当发现该节点不是属于该路径和，需要移除，返回上一个节点
3. 当查找一条路径，最终保存到二维 vector 里

## Path Sum III「LeetCode 437」

题目：

```
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf,

but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
```
