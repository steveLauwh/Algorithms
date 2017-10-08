// 借助栈实现
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;

        while (root || !stack.empty()) {
            while (root) {
                stack.push(root);
                
                root = root->left;
            }
            
            root = stack.top();
            stack.pop();
            
            res.push_back(root->val);
            root = root->right;
        }
        
        return res;
    }
    
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if (!root) {
            return vector<int>();
        }
        
        __inorderTraversal(root, res);
        
        return res;
    }
    
private:
    void __inorderTraversal(TreeNode* root, vector<int> &res) {
        if (root) {
            __inorderTraversal(root->left, res);
            res.push_back(root->val);
            __inorderTraversal(root->right, res);
        }
    }
};
