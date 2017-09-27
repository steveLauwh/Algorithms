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
    int maxDepth(TreeNode* root) {
        if(root == NULL)   
            return 0;
        
        int leftLength = maxDepth(root->left);
        int rightLength = maxDepth(root->right);
        
        return max(leftLength, rightLength) + 1;
    }
};
