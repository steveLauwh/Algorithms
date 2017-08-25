class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        
        for (int i = 0; i < length; i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        
        return s;
    }
};
