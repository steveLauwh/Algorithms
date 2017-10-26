// unordered_set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums){
            if(s.count(i))
                return true;
            s.insert(i);
        }
        return false;
    }
};

// unordered_map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        
        unsigned int n = nums.size();
        
        for (unsigned int i = 0; i < n; i++) {
            if (m.find(nums[i]) != m.end()) {
                return true;
            }
            
            ++m[nums[i]];
        }
     
        return false;
    }
};

// sort
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        if(nums.size() < 2)
            return false;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < (nums.size()-1); i++) {
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};
