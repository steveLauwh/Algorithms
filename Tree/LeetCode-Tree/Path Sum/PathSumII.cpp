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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        
        if (!root) {
            return ret;
        }
               
        vector<int> temp;
        
        dfs(root, sum, temp, ret);
        
        return ret;
    }

private:
    void dfs(TreeNode* root, int sum, vector<int>& temp, vector<vector<int>>& ret) {
        if (!root) {
            return;
        }
        
        // 节点入一维 vector
        temp.push_back(root->val);
        
        // 递归终止条件
        if (sum == root->val && !root->left && !root->right) {
            ret.push_back(temp);
        }
        
        helper(root->left, sum - root->val, temp, ret);
        helper(root->right, sum - root->val, temp, ret);
        
        // 不属于路径和，删除，返回上一个节点
        temp.pop_back();
    }
};
