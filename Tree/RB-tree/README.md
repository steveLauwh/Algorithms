## RB-tree 红黑树

### 红黑树的性质

红黑树本质是一个二叉搜索树，每个节点要么是红色，要么是黑色，加上一些特性，变成平衡二叉搜索树。

红黑树的插入、删除、查找操作的时间复杂度是 O(logN)。

红黑树的高度在 [logN, logN+1]。

* 规则 1：每个节点不是红色，就是黑色；
* 规则 2：根节点必须是黑色；
* 规则 3：如果一个节点是红色，那么它的孩子必须是黑色；
* 规则 4：任何一个节点向下遍历到其叶子节点，所经过的黑色节点必须相等；
* 规则 5：空节点必须是黑色；

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

STL 源码：
```cpp
typedef bool _Rb_tree_Color_type;
const _Rb_tree_Color_type _S_rb_tree_red = false;
const _Rb_tree_Color_type _S_rb_tree_black = true;

struct _Rb_tree_node_base
{
    typedef _Rb_tree_Color_type _Color_type;
    typedef _Rb_tree_node_base* _Base_ptr;
    
    _Color_type _M_color;  // 颜色
    _Base_ptr _M_parent;   // 父亲节点
    _Base_ptr _M_left;     // 左孩子节点
    _Base_ptr _M_right;    // 右孩子节点
    
    // 找值最小节点
    static _Base_ptr _S_minimum(_Base_ptr __x)
    {
        while (__x->_M_left != 0) __x = __x->_M_left;
        return __x;
    }
    
    // 找值最大节点
    static _Base_ptr _S_maximum(_Base_ptr __x)
    {
        while (__x->_M_right != 0) __x = __x->_M_right;
        return __x;
    }
}

template <class _Value>
struct _Rb_tree_node : public _Rb_tree_node_base
{
    typedef _Rb_tree_node<_Value>* _Link_type;
    _Value _M_value_field;  // 键值
};
```

### 红黑树的旋转

红黑树的旋转分为左旋转和右旋转。

旋转操作(Rotate)的目的是使节点颜色符合定义，让红黑树的高度达到平衡。

任何插入操作，当节点插入后，都要做一次调整操作，将树的状态调整到符合 RB-tree 的要求。

在做旋转操作时，节点的位置改变，那么该节点的父亲节点，左右孩子节点都要重新赋值。

**左旋转**

当在某个节点 pivot 上，做左旋转操作时，当这个 pivot 的节点右孩子 Y 不为空，那么以 pivot 到 Y 之间为轴进行左旋转，此时 Y 就在原先 pivot 上，pivot 作为Y的左孩子，Y 的左孩子变成 pivot 的右孩子。

```
      p                             p 
     /                             / 
    x                             y 
   / \                           / \ 
  lx  y      ---左旋转--->      x  ry 
     / \                       / \ 
    ly ry                     lx ly 
```

```cpp
inline void _Rb_tree_rotate_left(_Rb_tree_node_base* __x, _Rb_tree_node_base*& __root)
{
    _Rb_tree_node_base* __y = __x->_M_right;   // y 是 x 的右孩子节点
    __x->M_right = __y->_M_left;    // 将 y 的左孩子节点 赋值到 x 的右孩子节点
    
    if (__y->_M_left != 0)
        __y->_M_left->_M_parent = __x;  // y 的左孩子节点的父亲节点就是 x
    __y->_M_parent = __x->_M_parent;    // y 取代 x 的位置，y 的父亲节点就是 x 的父亲节点
    
    // 更新 p，y 是位于 p 的左孩子还是右孩子
    if (__x == __root)
        __root = __y;
    else if (__x == __x->_M_parent->_M_left)
        __x->_M_parent->_M_left = __y;
    else 
        __x->_M_parent->_M_right = __y;
    
    __y->_M_left = __x;   // y 的左孩子就是 x
    __x->_M_parent = __y; // x 的父亲节点就是 y
}
```

**右旋转**

当在某个节点 pivot 上，做右旋转操作时，当这个 pivot 的节点左孩子 Y 不为空，那么以 pivot 到 Y 之间为轴进行左旋转，此时 Y 就在原先 pivot 上，pivot 变成Y的右孩子，Y 的右孩子变成 pivot 的左孩子。

```
        p                      p 
       /                      / 
      x                      y 
     / \                    / \ 
    y  rx   ---右旋转--->  ly  x 
   / \                        / \ 
  ly  ry                     lx rx 
```

```cpp
inline void _Rb_tree_rotate_right(_Rb_tree_node_base* __x, _Rb_tree_node_base*& __root)
{
    _Rb_tree_node_base* __y = __x->_M_left;  // y 位于 x 的左孩子节点
    __x->_M_left = __y->_M_right;   // 将 y 的右孩子节点 赋值给 x 的左孩子节点
    if (__y->_M_right != 0)     // 如果 y 的右孩子节点不为空
        __y->_M_right->_M_parent = __x;   // y 的右孩子节点的父亲节点就是 x
    __y->_M_parent = __x->_M_parent;   // y 取代 x 的位置，y 的父亲节点就是 x 的父亲节点

    // 更新 p，y 是位于 p 的左孩子还是右孩子
    if (__x == __root)
        __root = __y;
    else if (__x == __x->_M_parent->_M_right)
        __x->_M_parent->_M_right = __y;
    else
        __x->_M_parent->_M_left = __y;
        
    __y->_M_right = __x;  // y 的右孩子就是 x
    __x->_M_parent = __y; // x 的父亲节点就是 y
}
```

### 红黑树的插入

如果是第一次插入，由于原树为空，所以只会违反红-黑树的规则 2，所以只要把根节点涂黑即可。

在红黑树中插入节点必须为红色，那么根据红黑树规则，该插入节点的父亲节点必须为黑，如果插入节点没有符合上述条件，就必须调整颜色并旋转树形。

红黑树的插入相当于在二叉搜索树插入的基础上，为了重新恢复平衡，需要继续做调整(`_Rb_tree_rebalance`)操作。

```
// 从根节点出发
void _M_insert(_Rb_tree_node<_Value>* node, _Rb_tree_node<_Value>*& root)
{
    _Rb_tree_node<_Value> *y = NULL;
    _Rb_tree_node<_Value> *x = root;  // root 根节点
    
    while (x != NULL)
    {
        y = x;
        if (node->_M_value_field < x->_M_value_field)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    
    node->parent = y;  //找到了位置，将当前 y 作为 node 的父节点  
    
    // 判断 node 是插在左子节点还是右子节点  
    if (y)
    {
        if (node->_M_value_field < y->_M_value_field)
        {
            y->left = node;
        }
        else
        {
            y->right = node;
        }
    }
    else 
    {
        root = node;
    }
    
    // 调整
    _Rb_tree_rebalance(node, root);
}
```


**插入需要颜色改变和旋转调整的三种情况**

* 插入节点的父亲节点是红色，叔叔节点是红色，调整颜色操作
* 插入节点的父亲节点是红色，叔叔节点是黑色，插入节点是父亲节点的左孩子节点，做旋转操作
* 插入节点的父亲节点是红色，叔叔节点是黑色，插入节点是父亲节点的右孩子节点，做旋转操作

插入调整的 STL 源码：
```cpp
inline void _Rb_tree_rebalance(_Rb_tree_node_base* __x, _Rb_tree_node_base*& __root)
{
    __x->_M_color = _S_rb_tree_red; // 新节点必为红色
    while (__x != __root && __x->_M_parent->_M_color == _S_rb_tree_red) {  // 插入节点的父亲节点是红色
        if (__x->_M_parent == __x->_M_parent->_M_parent->_M_left) { // 父亲节点为祖父节点的左孩子节点
            _Rb_tree_node_base* __y = __x->_M_parent->_M_parent->_M_right; // 令 y 为叔叔节点，作为祖父节点的右孩子节点
            if (__y && __y->_M_color == _S_rb_tree_red) { // 叔叔节点存在，且为红色
                __x->_M_parent->_M_color = _S_rb_tree_black; // 将父亲节点的颜色改变为黑色
                __y->_M_color = _S_rb_tree_black; // 将叔叔节点的颜色改变为黑色
                __x->_M_parent->_M_parent->_M_color = _S_rb_tree_red;  // 将祖父节点的颜色改变为红色
                __x = __x->_M_parent->_M_parent; // 将插入节点指向祖父节点
            }
            else { // 无叔叔节点，或者叔叔节点为黑色，做旋转操作
                if (__x == __x->_M_parent->_M_right) {  // 插入节点是父亲节点的右孩子节点
                    __x = __x->_M_parent; // 指向插入节点的父亲节点
                    _Rb_tree_rotate_left(__x, __root); // 左旋转操作
                }
                __x->_M_parent->_M_color = _S_rb_tree_black;  // 将插入节点的父亲节点改为红色
                __x->_M_parent->_M_parent->_M_color = _S_rb_tree_red; // 祖父节点为红色
                _Rb_tree_rotate_right(__x->_M_parent->_M_parent, __root); // 将祖父节点做右旋转操作
            }
        }
        else { // 父亲节点为祖父节点的右孩子节点
            _Rb_tree_node_base* __y = __x->_M_parent->_M_parent->_M_left; // 令 y 为叔叔节点，作为祖父节点的左孩子节点
            if (__y && __y->_M_color == _S_rb_tree_red) { // 叔叔节点存在，且为红色
                __x->_M_parent->_M_color = _S_rb_tree_black; // 将父亲节点的颜色改变为黑色
                __y->_M_color = _S_rb_tree_black; // 将叔叔节点的颜色改变为黑色
                __x->_M_parent->_M_parent->_M_color = _S_rb_tree_red; // 将祖父节点的颜色改变为红色
                __x = __x->_M_parent->_M_parent; // 将插入节点指向祖父节点
            }
            else { // 无叔叔节点，或者叔叔节点为黑色，做旋转操作
                if (__x == __x->_M_parent->_M_left) { // 插入节点是父亲节点的左孩子节点
                    __x = __x->_M_parent; // 指向插入节点的父亲节点
                    _Rb_tree_rotate_right(__x, __root); // 右旋转操作
                }
                __x->_M_parent->_M_color = _S_rb_tree_black; // 将插入节点的父亲节点改为黑色
                __x->_M_parent->_M_parent->_M_color = _S_rb_tree_red; // 祖父节点为红色
                _Rb_tree_rotate_left(__x->_M_parent->_M_parent, __root); // 将祖父节点做左旋转操作
            }
        }
    }
    __root->_M_color = _S_rb_tree_black;  // 根节点永远为黑
}
```

### 红黑树的删除

## 参考资料

* <<STL源码剖析 - stl_tree.h>>
* http://algs4.cs.princeton.edu/33balanced/
* http://blog.csdn.net/v_july_v/article/details/6105630
* http://blog.csdn.net/eson_15/article/details/51144079
* https://zhuanlan.zhihu.com/p/24367771
* https://zhuanlan.zhihu.com/p/24795143?refer=dreawer
* 红黑树在线图示：https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
