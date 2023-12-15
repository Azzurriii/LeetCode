class Solution {
public:
    int divide(int dividend, int divisor) {
         
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long x = static_cast<long long>(dividend) / divisor;
        return static_cast<int>(x);
    }
};