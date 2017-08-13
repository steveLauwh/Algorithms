#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// 二叉搜索树
template <typename Value>
class BST
{
private:
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
    
    BSTNode *root; // 根节点
    int count;     // 树的节点个数
  
public:
    
    // 构造函数, 默认构造一棵空二叉搜索树
    BST()
    {
        root = NULL;
        count = 0;
    }

    ~BST()
    {

    }

    // 返回二叉搜索树的节点个数
    int size()
    {
        return count;
    }

    // 判断二叉搜索树是否为空
    int isEmpty()
    {
        return count == 0;
    }

    // 插入节点 insert 操作
    void insert(Value value)
    {
        root = recursionInsertNode(root, value);
    }
    
    // 查找 search 操作：查找二叉搜索树中是否存在键值为value
    bool search(Value value)
    {
        return recursionSearch(root, value);
    }
    
    // 前序遍历 preOrder
    void preOrder()
    {
        recursionPreOrder(root);
    }
    
    // 中序遍历 inOrder
    void inOrder()
    {
        recursionInOrder(root);
    }
    
    // 后序遍历 postOrder
    void postOrder()
    {
        recursionPostOrder(root);
    }
    
    
private:
    
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
            while (current)
            {
                s.push(current);
                current = current->left; // 一直向左遍历，直到为空
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
};

int main()
{
    int arr[] = {28, 16, 30, 13, 22, 29, 42};
    
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    
    BST<int> bst = BST<int>();
    
    for (int i = 0; i < arrLength; i++)
    {
        //arr[i] = i;
        bst.insert(arr[i]);
    }
    
    cout << bst.size() << endl;
    
    bst.insert(99);
    
    cout << bst.size() << endl;
    
    cout << bst.search(5) << endl;
    
    cout << bst.search(12) << endl;
    
    bst.preOrder();
    bst.inOrder();
    bst.postOrder();
    
    return 0;
}
