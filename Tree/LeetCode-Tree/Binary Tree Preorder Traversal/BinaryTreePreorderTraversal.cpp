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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        __preorderTraversal(root, res);
        
        return res;
    }
    
private:
    void __preorderTraversal(TreeNode* root, vector<int> &res) {
        if (root) {
            res.push_back(root->val);   
            
            __preorderTraversal(root->left, res);
            __preorderTraversal(root->right, res);
        }
    }
};

// 迭代，借助栈
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* temp = root;
        vector<int> res;
        stack<TreeNode*> st;
        
        if (!temp) {
            return vector<int>();
        }
        
        while (temp || st.size() > 0) {
            if (temp) {
                st.push(temp);
                res.push_back(temp->val);
                temp = temp->left;
            } else {
                temp = st.top();
                st.pop();
                temp = temp->right;
            }
        }
        
        return res;
    }
};
