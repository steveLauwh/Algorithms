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
