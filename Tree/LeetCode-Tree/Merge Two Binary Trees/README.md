## Merge Two Binary Trees「LeetCode 617」

题目：合并两个二叉树，都存在的结点，就将结点值加起来，否则空的位置就由另一个树的结点来代替。

```
Given two binary trees and imagine that when you put one of them to cover the other, 

some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, 

then sum node values up as the new value of the merged node. Otherwise, 

the NOT null node will be used as the node of new tree.

Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
Note: The merging process must start from the root nodes of both trees.
```

解题思路：递归思想

1. 两个二叉树，如果两个二叉树，都有节点，就相加，如果一边没有，另一边有，就用有的代替
2. 如果 t1 不存在，则直接返回 t2，反之，如果 t2 不存在，则直接返回 t1
3. 如果上面两种情况都不满足，那么以 t1 和 t2 的结点值之和建立新结点 t
4. 然后对 t1 和 t2 的左子结点调用递归并赋给t的左子结点，再对 t1 和 t2 的右子结点调用递归并赋给 t 的右子结点，返回t结点即可

