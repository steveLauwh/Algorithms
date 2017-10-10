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
     vector<vector<int> > levelOrder(TreeNode *root) {
         vector<vector<int>> res;
         
         if (!root) {
             return res;
         }
         
         queue<TreeNode*> q;
         
         q.push(root);
         
         while (!q.empty()) {
             vector<int> levelRes;
             
             int n = q.size();
             
             for (int i = 0; i < n; i++) {
                 TreeNode *node = q.front();
                 
                 q.pop();
                 
                 levelRes.push_back(node->val);
                 
                 if (node->left) {
                     q.push(node->left);   
                 }
                 
                 if (node->right) {
                     q.push(node->right);   
                 }
             }
             
             res.push_back(levelRes);
         }
         
         return res;
     }
 };
