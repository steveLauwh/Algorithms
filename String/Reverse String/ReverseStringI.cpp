// 首尾两两交换

class Solution {
public:
    string reverseString(string s) {
        int length = s.size();
        
        for (int i = 0; i < length/2; i++) {
            char temp = s[i];
            s[i] = s[length - 1 -i];
            s[length - 1 -i] = temp;            
        }
        
        return s;
    }
};
