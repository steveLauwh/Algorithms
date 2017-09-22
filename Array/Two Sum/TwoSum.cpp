class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> maps;
        
        vector<int> result;
        
        int n = nums.size();
        
        // 遍历，map 数据
        for (int i = 0; i < n; i++) {
            maps[nums[i]] = i;
        }
        
        // 遍历，找差值是否存在
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            
            // 找到差值
            if (maps.count(diff) && maps[diff] != i) {
                result.push_back(i);
                result.push_back(maps[diff]);
                break;
            }
        }
        
        return result;
    }
};

// 简洁版
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if(map.count(temp)){
                return vector<int>{i,map[target-nums[i]]};
            } else {
                map[nums[i]] = i; 
            }
        }
    }
};
