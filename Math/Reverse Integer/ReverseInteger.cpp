class Solution {
public:
    int reverse(int x) {
        long long res = 0;  // 返回值定义64位，防止原始旋转后溢出
        
        while (x) {
            res = res * 10 + x % 10;
            
            x = x / 10;
        }
        
        return (INT_MIN > res || res > INT_MAX) ? 0 : res;
    } 
};
