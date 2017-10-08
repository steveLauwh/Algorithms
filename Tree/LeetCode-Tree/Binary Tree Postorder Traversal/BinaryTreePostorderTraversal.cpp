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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        __postorderTraversal(root, res);
        
        return res;
    }
    
private:
    void __postorderTraversal(TreeNode* root, vector<int> &res) {
        if (root) {
            __postorderTraversal(root->left, res);
            __postorderTraversal(root->right, res);
            
            res.push_back(root->val);
        }
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if (!root) {
            return res;
        }
        
        stack<TreeNode*> stack;
        
        stack.push(root);
        
        TreeNode *p = root;
        
        while (!stack.empty()) {
            TreeNode *top = stack.top();
            
            if ((!top->left && !top->right) || top->left == p || top->right == p) {
                res.push_back(top->val);
                
                stack.pop();
                p = top;
            } else {
                if (top->right) {
                    stack.push(top->right);
                }
                
                if (top->left) {
                    stack.push(top->left);
                }
            }
        }
        
        return res;
    }
};
