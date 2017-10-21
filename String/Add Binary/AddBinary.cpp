class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        
        int aLength = a.size() - 1;
        int bLength = b.size() - 1;
        int carry = 0;
        
        while (aLength >= 0 || bLength >= 0) {
            // 三目运算符
            int m = (aLength >= 0 ? a[aLength--] - '0': 0);
            int n = (bLength >= 0 ? b[bLength--] - '0': 0);
            
            int sum = m + n + carry;
            
            ret = to_string(sum % 2) + ret;
            
            carry = sum / 2;
        }
        
        return carry == 1 ? "1" + ret : ret;
    }
};
