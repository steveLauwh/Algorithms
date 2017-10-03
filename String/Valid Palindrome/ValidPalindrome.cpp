class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            if (!isAlphaNum(s[left])) {
                left++;
            } else if (!isAlphaNum(s[right])) {
                right--;
            } else if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32) {
                return false;
            } else {
                left++;
                right--;
            }        
        }
        
        return true;
    }
private:
    bool isAlphaNum(char &c) {
        return ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) || ( c >= '0' && c <= '9' );
    }
};
