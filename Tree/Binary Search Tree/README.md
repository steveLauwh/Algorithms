## 二分查找法

二分查找法用于查找问题，对于有序数列，才能使用二分查找法。

二分查找法的实现方法：迭代 和 递归。

![](https://github.com/steveLauwh/Data-Structures-And-Algorithms/raw/master/Tree/image/Binary%20Search%20Method.PNG)

`int mid = low + (high - low) / 2;`

## 二分搜索树

二分搜索树的特点：

* 每个节点的键值大于左孩子，小于右孩子
* 不一定是完全二叉树，二叉搜索树的节点不好用数组表示
* 高效地查找、插入、删除元素
* 使用递归，可以方便处理

|         | 查找元素 |  插入元素  | 删除元素|
| --------| :-----: | :----:  |:----:  |
| 普通数组 | O(n) |  O(n) |O(n)|
| 顺序数组 |   O(logn)   |  O(n)   |O(n)|
| 二分搜索树|    O(logn)     |  O(logn)  |O(logn) |
