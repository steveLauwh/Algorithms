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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        
        int left = 0, right = nums.size() - 1;
        
        return sortedArrayToBST(nums, left, right);
    }
    
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        TreeNode *res = NULL;
        
        if (left == right) {
            return new TreeNode(nums[left]);
        } else if (left < right) {
            int mid = left + (right - left) / 2;
        
            res = new TreeNode(nums[mid]);
        
            res->left = sortedArrayToBST(nums, left, mid - 1);
            res->right = sortedArrayToBST(nums, mid + 1, right);
        } else {
            return NULL;
        }
    
        return res;
    }
};
