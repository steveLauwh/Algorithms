## AVL Tree

AVL 树本质上是一棵平衡二叉搜索树，其平衡条件是每个结点的左右子树的高度之差的绝对值（平衡因子）最多为 1。

在大量的随机数据中，AVL 树表现要好很多。

AVL 树查找、插入和删除在平均和最坏情况下都是 O(logN)，增加和删除可能需要通过一次或多次树旋转来重新平衡这个树。

### 四种情况导致二叉搜索树不平衡

* LL：插入一个新节点到根节点的左子树（Left）的左子树（Left），导致根节点的平衡因子由1变为2

* RR：插入一个新节点到根节点的右子树（Right）的右子树（Right），导致根节点的平衡因子由-1变为-2

* LR：插入一个新节点到根节点的左子树（Left）的右子树（Right），导致根节点的平衡因子由1变为2

* RL：插入一个新节点到根节点的右子树（Right）的左子树（Left），导致根节点的平衡因子由-1变为-2

针对四种情况可能导致的不平衡，可以通过旋转使之变平衡。有两种基本的旋转：

* 左旋转：将根节点旋转到（根节点的）右孩子的左孩子位置
* 右旋转：将根节点旋转到（根节点的）左孩子的右孩子位置

### AVL 树的旋转操作

AVL 树的基本结构：

```c++
struct TreeNode {
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
};

int Height(TreeNode* node) {
    return node->height;
}
```

> LL(向右旋转操作)

根节点成为它的左孩子的右孩子，根节点的左孩子的右孩子成为根节点的左孩子。

```c++
TreeNode* RightRotate(TreeNode* root) {
    TreeNode *b = root->left;
    root->left = b->right;
    b->right = root;
    
    root->height = Max(Height(root->left), Height(root->right)) + 1;
    b->height = Max(Height(b->left), Height(b->right)) + 1;
    
    return b;
}
```

> RR(向左旋转操作)

根节点的右孩子成为新树的根节点，根节点的右孩子的左孩子成为根节点的右孩子。

```c++
TreeNode* LeftRotate(TreeNode* root) {
    TreeNode* b = root->right;
    root->right = b->left;
    b->left = root;
    
    root->height = Max(Height(root->left), Height(root->right)) + 1;
    b->height = Max(Height(b->left), Height(b->right)) + 1;
    
    return b;
}
```

> LR(左右旋转，先根节点的左孩子进行左旋转，后根节点进行右旋转)

```c++
TreeNode* LeftRightRotate(TreeNode* root) {
    root->left = LeftRotate(root->left);
    
    return RightRotate(root);
}
```

> RL(右左旋转，先根节点的右孩子进行右旋转，后根节点进行左旋转)

```c++
TreeNode* RightLeftRotate(TreeNode* root) {
    root->right = RightRotate(root->left);
    
    return LeftRotate(root);
}
```

## AVL 树的插入和删除操作
