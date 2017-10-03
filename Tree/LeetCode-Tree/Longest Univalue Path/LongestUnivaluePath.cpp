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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int res = 0;
        
        dfs(root, res);
        
        return res;
    }
    
private:
    int dfs(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }
        
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        
        int arrowLeft = 0, arrowRight = 0;
        
        if (root->left && root->left->val == root->val) {
            arrowLeft = 1 + left;
        }
        
        if (root->right && root->right->val == root->val) {
            arrowRight = 1 + right;
        }
        
        res = max(res, arrowLeft + arrowRight);
        
        return max(arrowLeft, arrowRight);
    }
};
