class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {        
        int first = 0, last = numbers.size() - 1;
        
        while (first < last) {
            if (numbers[first] + numbers[last] == target) {
                int ret[2] = {first+1, last+1};
                return vector<int>(ret, ret+2);
            } else if (numbers[first] + numbers[last] < target) {
                first++;
            } else {
                last--;
            }
        }
    }
};
