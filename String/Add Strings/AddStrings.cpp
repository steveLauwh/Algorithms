class Solution {
public:
    string addStrings(string num1, string num2) {
        string &shortString = (num1.size() <= num2.size()) ? num1 : num2;
        string &longString = (num1.size() > num2.size()) ? num1 : num2;
        string result;
        
        int shortLength = shortString.size();
        int longLength = longString.size();
        
        int carry = 0;
             
        for (int i = shortLength - 1, j = longLength - 1; j >= 0 ; i--, j--) {
            int sum = 0;
            if (i >= 0) {
                sum = shortString[i] - '0' + longString[j] - '0' + carry;
            } else {
                sum = longString[j] - '0' + carry;
            }
            
            carry = sum / 10;   // 进位
            result = char(sum % 10 + '0') + result; // 字符串连接
        }
        
        if (carry) {
            result = char(carry + '0') + result;
        }
        
        return result;
    }
};
