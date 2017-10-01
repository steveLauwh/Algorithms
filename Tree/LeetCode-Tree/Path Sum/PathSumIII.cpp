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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> out;
        
        dfs(root, sum, 0, out, res);
        
        return res;
    }
    
private:
    void dfs(TreeNode* root, int sum, int curSum, vector<TreeNode*>& out, int& res) {
        if (!root) {
            return;
        }
        
        curSum += root->val;
        
        out.push_back(root);
        
        if (curSum == sum) {
            ++res;
        }
        
        int t = curSum;
        
        for (int i = 0; i < out.size() - 1; i++) {
            t -= out[i]->val;
            
            if (t == sum) {
                ++res;
            }
        }
            
        dfs(root->left, sum, curSum, out, res);
        dfs(root->right, sum, curSum, out, res);
        
        out.pop_back();
    }
    
};
