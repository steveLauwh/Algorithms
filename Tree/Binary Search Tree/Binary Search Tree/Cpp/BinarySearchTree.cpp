#include <iostream>

using namespace std;

// 二叉搜索树 (Key, Value)
template <typename Key, typename Value>
class BST
{
private:
    // 二叉搜索树的节点
    struct BSTNode
    {
        Key key;
        Value value;
        BSTNode *left;
        BSTNode *right;
      
        BSTNode(Key key, Value value)
        {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }        
    };
    
    BSTNode *root; // 根节点
    int count;     // 节点个数
  
public:
  BST()
  {
      root = NULL;
      count = 0;
  }
  
  ~BST()
  {
      
  }
  
  int size()
  {
      return count;
  }
  
  int isEmpty()
  {
      return count == 0;
  }
  
};

int main()
{
    return 0;
}
