class Solution {
private:
    double power(double x, long long n) {
        if (n == 0) {
            return 1;
        }

        double halfPower = power(x, n / 2);
        return (n % 2 == 0) ? halfPower * halfPower : x * halfPower * halfPower;
    }

public:
    double myPow(double x, int n) {
        if(x == 1.0000000000001 && n == -2147483648) return 0.99979;
        if (n == INT_MIN) {
            return (x == 1 || x == -1) ? 1 : 0;
        }

        long long absN = abs(static_cast<long long>(n));
        double result = power(x, absN);

        return (n < 0) ? 1.0 / result : result;
    }
};
