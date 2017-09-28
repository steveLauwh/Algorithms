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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        // 先比较根节点的左右子树的高度差
        if (abs(getDepth(root->left) - getDepth(root->right)) > 1) {
            return false;
        }
        
        // 继续递归，判断左右子树的平衡
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
private:
    int getDepth(TreeNode* root) {
        if (!root) {
            return 0; 
        }
        
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};

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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        if (checkDepth(root) == -1) {
            return false;
        } else {            
            return true;
        }
    }
    
private:
    int checkDepth(TreeNode* root) {
        if (!root) {
            return 0; 
        }
        
        int leftLength = checkDepth(root->left);
        
        if (leftLength == -1) {
            return -1;
        }
        
        int rightLength = checkDepth(root->right);
        
        if (rightLength == -1) {
            return -1;
        }
        
        if (abs(leftLength - rightLength) > 1) {
            return -1;
        } else {
            return max(leftLength, rightLength) + 1;
        }
    }
};
