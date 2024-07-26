class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: handle overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }


        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Use long long to handle absolute values
        long long absDividend = abs(dividend);
        long long absDivisor = abs(divisor);

        long long result = 0;

        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            absDividend -= tempDivisor;
            result += multiple;
        }

        return negative ? -result : result;
    }
};