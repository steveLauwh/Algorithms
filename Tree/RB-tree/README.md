## RB-tree 红黑树

### 红黑树的性质

红黑树本质是一个二叉搜索树，每个节点要么是红色，要么是黑色，加上一些特性，变成平衡二叉搜索树。

红黑树的插入、删除、查找操作的时间复杂度是 O(logN)。

红黑树的高度在 [logN, logN+1]。

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

### 红黑树的旋转

红黑树的旋转分为左旋转和右旋转。

旋转操作(Rotate)的目的是使节点颜色符合定义，让红黑树的高度达到平衡。

任何插入操作，当节点插入后，都要做一次调整操作，将树的状态调整到符合 RB-tree 的要求。

**左旋转**

当在某个节点 pivot 上，做左旋转操作时，当这个 pivot 的节点右孩子 Y 不为空，那么以 pivot 到 Y 之间为轴进行左旋转，此时 Y 就在原先 pivot 上，pivot 作为Y的左孩子，Y 的左孩子变成 pivot 的右孩子。

**右旋转**

当在某个节点 pivot 上，做右旋转操作时，当这个 pivot 的节点左孩子 Y 不为空，那么以 pivot 到 Y 之间为轴进行左旋转，此时 Y 就在原先 pivot 上，pivot 变成Y的右孩子，Y 的右孩子变成 pivot 的左孩子。

### 红黑树的插入



## 参考资料

* <<STL源码剖析 - stl_tree.h>>
* http://algs4.cs.princeton.edu/33balanced/
* http://blog.csdn.net/v_july_v/article/details/6105630
* http://blog.csdn.net/eson_15/article/details/51144079
* https://zhuanlan.zhihu.com/p/24367771
* https://zhuanlan.zhihu.com/p/24795143?refer=dreawer
* 红黑树在线图示：https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
