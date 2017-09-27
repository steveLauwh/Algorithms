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
        
        queue<TreeNode*> q;
        
        int count = 0;
        
        // 首先根节点入队列
        q.push(root);
        
        while (!q.empty()) {
            ++ count;
            
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                TreeNode *t = q.front();
                
                // 队列头部元素出列
                q.pop();
                
                // 出列的节点有左右节点，入队列
                if (t->left) {
                    q.push(t->left);
                }
                
                if (t->right) {
                    q.push(t->right);
                }
            }
        }
        
        return count;
    }
};
