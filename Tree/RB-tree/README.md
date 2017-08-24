## RB-tree 红黑树

### 红黑树的性质

红黑树本质是一个二叉搜索树，每个节点要么是红色，要么是黑色，加上一些特性，变成平衡二叉搜索树。红黑树的插入、删除、查找操作的时间复杂度是 O(logN)。

* 每个节点不是红色，就是黑色；
* 根节点必须是黑色；
* 如果一个节点是红色，那么它的孩子必须是黑色；
* 任何一个节点向下遍历到其叶子节点，所经过的黑色节点必须相等；
* 空节点必须是黑色；

### 红黑树的数据结构

```cpp
struct Rb_tree_node
{
    bool color;
    struct Rb_tree_node *parent;
    struct Rb_tree_node *left;
    struct Rb_tree_node *right;
}
```


## 参考资料

* <<STL源码剖析 - stl_tree.h>>
* http://blog.csdn.net/v_july_v/article/details/6105630
* https://zhuanlan.zhihu.com/p/24367771
* https://zhuanlan.zhihu.com/p/24795143?refer=dreawer
* 红黑树在线图示：https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
