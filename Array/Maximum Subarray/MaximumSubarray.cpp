// 遍历
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, ret = INT_MIN;
        
        for (int number : nums) {
            curSum = max(number + curSum, number);
            ret = max(ret, curSum);
        }
        
        return ret;
    }
};

// 分冶法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
              
        return doHelper(nums, 0, nums.size() - 1);
    }

private:
    int doHelper(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nums[left];
        }
        
        int mid = left + (right - left) / 2;
        
        int leftMax = doHelper(nums, left, mid - 1);
        int rightMax = doHelper(nums, mid + 1, right);
        
        int midMax = nums[mid];
        
        int temp = midMax;
        
        for (int i = mid - 1; i >= left; i--) {
            temp += nums[i];
            midMax = max(midMax, temp);
        }
        
        temp = midMax;
        
        for (int i = mid + 1; i <= right; i++) {
            temp += nums[i];
            midMax = max(midMax, temp);
        }
        
        return max(midMax, max(leftMax, rightMax));
    }
};
