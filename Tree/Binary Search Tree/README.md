## 二分查找法

二分查找法用于查找问题，对于有序数列，才能使用二分查找法。

顺序查找：用链表实现，无法索引数据，查找时间复杂度 O(n)，无法保证数据有序。

二分查找：用数组保存数据，查找时间复杂度 O(logn)，保证有序。

二分查找法的实现方法：迭代 和 递归。

![](https://github.com/steveLauwh/Data-Structures-And-Algorithms/raw/master/Tree/image/Binary%20Search%20Method.PNG)

`int mid = low + (high - low) / 2;`

## 二叉搜索树

### 二叉搜索树的特点

* 每个节点的键值大于左孩子，小于右孩子
* 不一定是完全二叉树
* 高效地查找、插入、删除元素
* 使用递归，可以方便处理
* 链式结构，每个节点有一个键和关联的值

```cpp
// 二叉搜索树的节点
struct BSTNode
{
    Value value;
    BSTNode *left;
    BSTNode *right;

    BSTNode(Value value)
    {
        this->value = value;
        this->left = this->right = NULL;
    }        
};
```

|         | 查找元素 |  插入元素  | 删除元素|
| --------| :-----: | :----:  |:----:  |
| 普通数组 | O(n) |  O(n) |O(n)|
| 顺序数组 |   O(logn)   |  O(n)   |O(n)|
| 二叉搜索树|    O(logn)     |  O(logn)  |O(logn) |

### 二叉搜索树的缺点

当数据是顺序或者倒序，那么构造的二叉搜索树出现一边倒的情况，这样查找的时间复杂度达到 O(n)。

### 二叉搜索树—插入「insert」

结合二叉搜索树的特点，对于第一个要存入的值，设置为根节点；当插入节点的值小于根节点的值，将其移动到左子树上，与左孩子节点比较；当插入节点的值大于根节点的值，将其移动到右子树上，与右孩子节点比较。

插入新节点操作有 递归 和 非递归 两种实现方式。

**递归版的插入**

```cpp
// insert 内部使用递归实现
BSTNode* recursionInsertNode(BSTNode *node, Value value)
{
    if (!node)
    {
        count++;
        return new BSTNode(value);
    }

    if (value < node->value)  // 待插入节点的值小于当前节点的值
    {
        node->left = recursionInsertNode(node->left, value);
    }
    else if (value > node->value) // 待插入节点的值大于当前节点的值
    {
        node->right = recursionInsertNode(node->right, value);
    }
    else
    {
        //node->value = value; // 已存在
        cout << "insert the element is exist!" << endl;
    }

    return node;
}
```

**非递归版的插入**

```cpp
// insert 内部使用非递归实现
BSTNode* nonrecursionInsertNode(BSTNode *node, Value value)
{
    if (!node)
    {
        count++;
        return new BSTNode(value);
    }

    BSTNode *bstNode = node; // 保证函数返回是二叉搜索树的根节点

    while (bstNode)
    {
        // 待插入节点的值小于当前节点的值
        if (value < bstNode->value)
        {
            if (!(bstNode->left))
            {
                count++;
                bstNode->left = new BSTNode(value);
                break;
            }
            else
            {
                bstNode = bstNode->left;
            }              
        }
        else if (value > bstNode->value)         // 待插入节点的值大于当前节点的值
        {
            if (!(bstNode->right))
            {
                count++;
                bstNode->right = new BSTNode(value);
                break;
            }
            else
            {
                bstNode = bstNode->right;
            }
        }
        else
        {
            //bstNode->value = value;
            cout << "insert the element is exist!" << endl;
            break;
        }
    }

    return node;
}
```

### 二叉搜索树—查找「search」

查找是查找某一个节点是否在二叉搜索树中，如果存在，返回 true，否则 false。

查找操作有 递归 和 非递归 两种实现方式。

查找 和 包含 操作本质是一样的。

**递归版的查找**

```cpp
// search 内部使用递归实现
bool recursionSearch(BSTNode *node, Value value)
{
    if (!node)
    {
        return false;
    }

    if (node->value == value)
    {
        return true;
    }
    else if (value < node->value)
    {
        return recursionSearch(node->left, value);
    }
    else
    {
        return recursionSearch(node->right, value);
    }
}
```

**非递归版的查找**

```cpp
// search 内部使用非递归实现
bool nonrecursionSearch(BSTNode *node, Value value)
{
    if (!node)
    {
        return false;
    }

    while (node)
    {
        if (node->value == value)
        {
            return true;
        }
        else if (value < node->value)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    return false;
}
```

### 二叉搜索树—删除「remove」

如何删除二叉搜索树中的任意节点。

删除二分搜索树的任意一个节点，时间复杂度 O(logn)。

三种情况：删除只有左孩子的节点，删除只有右孩子的节点，删除左右都有孩子的节点。

* 删除只有左孩子的节点：将左孩子的节点代替要删除的节点。

* 删除只有右孩子的节点：将右孩子的节点代替要删除的节点。

* 当删除左右都有孩子的节点——Hubbard Deletion ：
  
  方法一：首先找到 删除节点d 的最小右孩子节点 s = min(d->right); s->left = d->left; s->right = delMin(d->right)；删除节点d。
  
  方法二：首先找到 删除节点d 的最大左孩子节点 s = max(d->left); s->left = delMax(d->left); s->right = d->right; 删除节点d。

```cpp
// 删除二叉搜索树中的任意节点
void remove(Value value)
{
    root = remove(root, value);
}

// 删除二叉搜索树中的任意节点
BSTNode* remove(BSTNode *node, Value value)
{
    if(!node)
    {
        return NULL;
    }

    if (value < node->value)
    {
        node->left = remove(node->left, value);
        return node;
    }
    else if (value > node->value)
    {
        node->right = remove(node->right, value);
        return node;
    }
    else
    {
        // value == node->value
        // 当删除节点的左子树为空
        if (!node->left)
        {
            BSTNode *current = node->right;
            delete node;
            count--;

            return current;
        }

        // 当删除节点的右子树为空
        if (!node->right)
        {
            BSTNode *current = node->left;
            delete node;
            count--;

            return current;  
        }

        // 当删除节点的左右子树不为空
        /* 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点s，用这个节点顶替待删除节点的位置 */
        BSTNode *s = new BSTNode(recursionminimum(node->right)); // 创建一份右子树的最小节点
        count++;

        // 关键地方
        s->left = node->left;
        s->right = recursionremoveMin(node->right);  // 调用删除最小值的接口

        delete node;
        count--;

        return s;
    }        
}
```

### 二叉搜索树—遍历「order」

二叉搜索树的遍历时间复杂度 O(n)，n 为树的节点个数。

> **前序遍历「preOrder」**

`根-->左-->右`

递归方式：先访问当前节点，再依次递归访问左子树和右子树。

非递归方式：为了把一个递归过程改为非递归过程，就需要自己维护一个辅助栈(队列)结构，记录遍历时的回退路径。

```cpp
stack<BSTNode*> s;
s.empty(); // 当前堆栈为空，返回true，否则不为空，返回 false
```

**递归版的前序遍历**

```cpp
// preOrder 内部使用递归实现
void recursionPreOrder(BSTNode *node)
{
    if (node)
    {
        cout << node->value << endl;
        recursionPreOrder(node->left);
        recursionPreOrder(node->right);
    }
}
```

**非递归版的前序遍历**

首先让根节点进栈，只要栈不为空，就可以做弹出操作，每次弹出一个结点，记得把它的左右结点都进栈，由于栈是先进后出，前序遍历是根左右遍历，那么右子树先进栈，再左子树进栈，这样可以保证右子树在栈中总处于左子树的下面。

```cpp
// preOrder 内部使用非递归实现，这里借用栈结构
void nonrecursionPreOrder(BSTNode *node)
{
    if (!node)
    {
        return;
    }

    stack<BSTNode*> s;
    s.push(node);  // 当前节点进栈

    while (!s.empty())  // 栈不为空
    {
        BSTNode *current = s.top();   
        cout << current->value << endl;

        s.pop();  // 先把当前节点出栈

        if (current->right) // 先右孩子节点进栈
        {
            s.push(current->right);
        }

        if (current->left) // 再左孩子节点进栈
        {
            s.push(current->left);
        }
    }        
}
```

> **中序遍历「inOrder」**

左-->根-->右

递归方式：先递归访问左子树，再访问自身，再递归访问右子树。

非递归方式：借助栈结构，首先把根节点入栈，当有左子树，一直循环，入栈；然后栈顶元素(最左边的左子树)弹出，然后把指针指向栈顶元素的右子树，当栈顶元素有右子树，就入栈，否则再弹出栈顶元素...

**递归版的中序遍历**

```cpp
// inOrder 内部使用递归实现
void recursionInOrder(BSTNode *node)
{
    if (node)
    {
        recursionInOrder(node->left);
        cout << node->value << endl;
        recursionInOrder(node->right);
    }
}
```

**非递归版的中序遍历**

```cpp
// inOrder 内部使用非递归实现，借用栈结构
void nonrecursionInOrder(BSTNode *node)
{
    if (!node)
    {
        return;
    }

    BSTNode *current = node;
    stack<BSTNode*> s;

    while (current || !s.empty())
    {
        while (current)  // 一直循环入左子树
        {
            s.push(current);
            current = current->left;
        }

        if (!s.empty())
        {
            current = s.top();
            cout << current->value << endl;
            s.pop();

            current = current->right;  // 关键地方，最左边的左子树(当前节点)，需要判断该当前节点是否有右子树节点
        }
    }
}
```

> **后序遍历「postOrder」**

左-->右-->根

递归方式：先递归访问左右子树，再访问自身节点。

非递归方式：可以在中序非递归遍历上改进，也可以利用双栈法，由于根节点是最后访问的节点，所以把根节点最先入栈2，栈1作为中间栈，栈2是存储经过后序遍历完的元素。

**递归版的后序遍历**

```cpp
// postOrder 内部使用递归实现
void recursionPostOrder(BSTNode *node)
{
    if (node)
    {
        recursionPostOrder(node->left);
        recursionPostOrder(node->right);
        cout << node->value << endl;
    }
}
```

**非递归版的后序遍历**

```cpp
// postOrder 内部使用非递归实现，双栈法
void nonrecursionPostOrder(BSTNode *node)
{
    if (!node)
    {
        return;
    }

    stack<BSTNode*> s1, s2;
    BSTNode *current = node;
    s1.push(node);

    while (!s1.empty())
    {
        current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left)
        {
            s1.push(current->left);
        }
        if (current->right)
        {
            s1.push(current->right);
        }
    }

    while(!s2.empty())
    {
        cout << s2.top()->value << endl;
        s2.pop();
    }       
}
```

> **层序遍历「levelOrder」**

借用队列 queue 结构，先根节点入队列，然后出列，再将根节点的左节点入列，右节点入列，依次……

```cpp
// 层序遍历，利用队列结构
void levelOrder(BSTNode *node)
{
    queue<BSTNode*> q;

    q.push(node);

    while (!q.empty())
    {
        BSTNode *current = q.front();  //指向队列的顶端
        q.pop();

        cout << current->value << endl;

        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
}
```

### 二叉搜索树—应用

> **查找二叉搜索树中的最小值**

一直向左遍历，直到为当前节点的左子树为空，则当前节点为最小值。

**递归版的查找二叉搜索树中的最小值**

```cpp
// 查找二叉搜索树中的最小值
Value minimum()
{
    assert(count != 0);

    BSTNode *node = recursionminimum(root);

    return node->value;
}

// 查找二叉搜索树的最小值所在节点
BSTNode* recursionminimum(BSTNode *node)
{
    if (node->left)
    {
        return recursionminimum(node->left);
    }

    return node;
}
```

**非递归版的查找二叉搜索树中的最小值**

```cpp
// 查找二叉搜索树中的最小值
Value minimum()
{
    assert(count != 0);

    BSTNode *node = nonrecursionminimum(root);

    return node->value;
}

// 查找二叉搜索树的最小值所在节点——非递归实现
BSTNode* nonrecursionminimum(BSTNode *node)
{
    while (node->left)
    {
        node = node->left;
    }

    return node;
}
```

> **查找二叉搜索树中的最大值**

一直向右遍历，直到为当前节点的右子树为空，则当前节点为最大值。

**递归版的查找二叉搜索树中的最大值**

```cpp
// 查找二叉搜索树中的最大值
Value maximum()
{
    assert(count != 0);

    BSTNode *node = recursionmaximum(root);

    return node->value;
}

// 查找二叉搜索树的最大值所在节点——递归实现
BSTNode* recursionmaximum(BSTNode *node)
{
    if (node->right)
    {
        return recursionmaximum(node->right);
    }

    return node;
}
```

**非递归版的查找二叉搜索树中的最大值**

```cpp
// 查找二叉搜索树中的最大值
Value maximum()
{
    assert(count != 0);

    BSTNode *node = nonrecursionmaximum(root);

    return node->value;
}

// 查找二叉搜索树的最大值所在节点——非递归实现
BSTNode* nonrecursionmaximum(BSTNode *node)
{
    while (node->right)
    {
        node = node->right;
    }

    return node;
}
```

> **删除二叉搜索树中的最小值**

删除二叉搜索树中的最小值所在节点，返回删除节点后新的二分搜索树的根。

递归操作，如果当前节点的左节点为空，就把当前节点的左节点为空，否则将当前节点的右节点赋给当前节点的左节点。

**递归版的删除二叉搜索树中的最小值**
```cpp
// 删除二叉搜索树的最小值所在节点——递归实现
BSTNode* recursionremoveMin(BSTNode *node)
{
    if (!node->left)
    {
        BSTNode *current = node->right;
        delete node;
        count--;

        return current;
    }

    node->left =  recursionremoveMin(node->left); // 关键地方

    return node;
}
```

**非递归版的删除二叉搜索树中的最小值**

```cpp
// 删除二叉搜索树的最小值所在节点——非递归实现
BSTNode* nonrecursionremoveMin(BSTNode *node)
{
    BSTNode *parent = node;
    BSTNode *temp = node;
    int num = 0;

    if (!temp->left)
    {
        BSTNode *current = temp->right;
        delete temp;
        count--;

        return current;
    }
    else
    {
        while (temp->left)
        {
            temp = temp->left;
            num++;
        }

        for (int i = 0; i < num-1; i++)
        {
            parent = parent->left;
        }

        if (temp->right)
        {
            parent->left = temp->right;
            delete temp;
            count--;   
        }
        else
        {
            parent->left = NULL;
            delete temp;
            count--;
        }
    }

    return node;
}
```

> **删除二叉搜索树中的最大值**

删除二叉搜索树中的最大值所在节点，返回删除节点后新的二分搜索树的根。

递归操作，如果当前节点的右节点为空，就把当前节点的右节点为空，否则将当前节点的左节点赋给当前节点的右节点。

**递归版的删除二叉搜索树中的最大值**
```cpp
// 删除二叉搜索树的最大值所在节点——递归实现
BSTNode* recursionremoveMax(BSTNode *node)
{
    if (!node->right)
    {
        BSTNode *current = node->left;
        delete node;
        count--;

        return current;
    }

    node->right = recursionremoveMax(node->right);

    return node;
}
```

**非递归版的删除二叉搜索树中的最大值**

```cpp
// 删除二叉搜索树的最大值所在节点——非递归实现
BSTNode* nonrecursionremoveMax(BSTNode *node)
{
    BSTNode *parent = node;
    BSTNode *temp = node;

    int num = 0;

    if (!temp->right)
    {
        BSTNode *current = temp->left;
        delete temp;
        count--;

        return current;
    }
    else
    {
        while (temp->right)
        {
            temp = temp->right;
            num++;
        }

        for (int i = 0; i < num-1; i++)
        {
            parent = parent->right;
        }

        if (temp->left)
        {
            parent->right = temp->left;
            delete temp;
            count--;   
        }
        else
        {
            parent->right = NULL;
            delete temp;
            count--;
        }
    }

    return node;
}
```

> **删除二叉搜索树中的所有节点**

后序遍历的应用——销毁二叉搜索树

递归，先删掉左子树节点，再删掉右子树节点，最后删掉当前节点。

```cpp
// 利用后序遍历来销毁二叉搜索树
void destroy(BSTNode *node)
{
    if (node)
    {
        destroy(node->left);
        destroy(node->right);

        delete node;         
        count--;
    }
}
```

### 二叉搜索树的局限性

当数据为顺序时，构造的二叉搜索树退化成链表，这样二叉搜索树的基本操作不高效，引入平衡二叉树(红黑树、2-3树、AVL树等)。
