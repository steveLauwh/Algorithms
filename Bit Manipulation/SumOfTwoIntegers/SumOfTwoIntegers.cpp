/**
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 */
// 内含迭代思想
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carray = a & b;
            int sum = a ^ b;
            a = sum;
            b = carray << 1;
        }
        
        return a;
    }
};
