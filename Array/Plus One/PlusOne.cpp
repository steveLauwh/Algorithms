class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int nums = digits.size();
        
        for (int i = nums - 1; i >= 0; i--) {
            
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        
        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
