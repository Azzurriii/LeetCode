class Solution {
public:
    int divide(int dividend, int divisor){
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long int quotient = 0;
    long long int temp = 0;
    long long int a = abs(dividend);
    long long int b = abs(divisor);
    for(int i = 31; i >= 0; i--){
        if(temp + (b << i) <= a){
            temp += b << i;
            quotient |= 1LL << i;
        }
    }
    quotient *= sign;
    if(quotient > INT_MAX || quotient < INT_MIN){
        return INT_MAX;
    }
    return quotient;
}
};