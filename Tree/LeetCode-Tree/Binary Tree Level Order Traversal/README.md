## Binary Tree Level Order Traversal「LeetCode 102」

题目： 二叉树层序遍历

```
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
```

解题思路：

1. 二叉树的层序遍历是典型的 BFS 应用，建立一个队列 queue
2. 先把根节点放入到队列中，while 循环判断队列是否为空，不为空，先从队列中取出根节点，然后判断根节点是否有左右子节点
3. 如果有左右子节点，分别入队列；每次从队列中取出一个节点，看该节点是否有左右子节点，有入队列
4. 此题涉及到二维向量存储，每次 for 遍历当前队列，存储到一维向量，遍历完后，把一维向量存储到二维向量中
