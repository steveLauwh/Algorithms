#include <iostream>

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
    
};

int main()
{
    int arr[100];
    
    BST<int> bst = BST<int>();
    
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i;
        bst.insert(arr[i]);
    }
    
    cout << bst.size() << endl;
    
    bst.insert(99);
    
    cout << bst.size() << endl;
    
    cout << bst.search(5) << endl;
    
    cout << bst.search(12) << endl;
    
    return 0;
}
