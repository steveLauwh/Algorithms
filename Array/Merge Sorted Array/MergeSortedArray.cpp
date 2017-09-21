class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count = m + n - 1;  // 合并后的长度
        
        --m;
        --n;
        
        while (m >= 0 && n >= 0) {  // 从尾部往前扫
            if (nums1[m] > nums2[n]) {
                nums1[count--] = nums1[m--];
            } else {
                nums1[count--] = nums2[n--];
            }
        }
        
        while (n >= 0) {
            nums1[count--] = nums2[n--];
        }
    }
};
