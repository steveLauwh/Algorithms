// 计数排序
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] = {0};
        
        int count = nums.size();
        
        // 计数
        for (int i = 0; i < count; i++) {
            colors[nums[i]] ++;
        }
        
        int index = 0;
        for (int i = 0; i < colors[0]; i++) {
            nums[index++] = 0;
        }
        
        for (int i = 0; i < colors[1]; i++) {
            nums[index++] = 1;
        }
        
        for (int i = 0; i < colors[2]; i++) {
            nums[index++] = 2;
        }
    }
};

// 三路快排
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1;
        int two = nums.size();
        
        for (int i = 0; i < two; ) {
            if (nums[i] == 1) {
                i++;
            } else if (nums[i] == 2) {   
                swap(nums[i], nums[--two]);
            } else {
                swap(nums[++zero], nums[i++]);
            }
        }
    }
};
