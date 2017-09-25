class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if (nums.empty() || ((k %= nums.size()) == 0)) {
            return ;
        }
        
        int n = nums.size();
        
        // 1. 前 n-k 个数字翻转
        reverse(nums.begin(), nums.begin() + n - k);
        
        // 2. k 个数字向右翻转
        reverse(nums.begin() + n - k, nums.end());
        
        // 3. 整体翻转
        reverse(nums.begin(), nums.end());
        
    }
};
