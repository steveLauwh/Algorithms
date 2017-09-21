class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int number = 0;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                nums[number++] = nums[i];
            }
        }
        
        return number;
    }
};
