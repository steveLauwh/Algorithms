class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int index = 0;
        int n = nums.size();
        
        // 比较，应从第二个元素开始遍历
        for (int i = 1; i < n; i++) {
            if (nums[index] != nums[i]) {  // 表示后面的元素不等于前面的元素，那么index需要先加1，再赋值
                nums[++index] = nums[i];
            }
        }
        
        return index + 1;
    }
};
