// 初始化要用长整型 long 的最小值，否则当数组中有 INT_MIN 存在时，不知道该返回 INT_MIN 还是最大值 first
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        
        for (int num : nums) {
            if (num == first || num == second || num == third)
                continue;  
            
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        
        return  (third == LONG_MIN) ? (int)first : (int)third;
    }
};

// set，时间复杂度 O(nlogn)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        
        set<int>::reverse_iterator it = s.rbegin();
        
        if (s.size() < 3) {
            return *it;
        }
        
        it++;
        it++;
        
        return *it;
    }
};
