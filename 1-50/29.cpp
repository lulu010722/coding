#include "header.h"

class Solution
{
private:
    pair<int, int> divideWithRemain(int dividend, int divisor)
    {
        bool isDividendNegative = dividend < 0;
        bool isDivisorNegative = divisor < 0;
        bool isDiffSign = isDividendNegative ^ isDivisorNegative;

        if (divisor == INT_MIN)
        {
            if (dividend == INT_MIN)
                return make_pair(1, 0);
            else
                return make_pair(0, dividend);
        }
        if (dividend == INT_MIN)
        {
            if (divisor == -1)
                return make_pair(INT_MAX, 0);
            auto result = divideWithRemain(-INT_MAX, divisor);
            if (abs(result.second - 1) == abs(divisor))
                return make_pair(result.first + (isDiffSign ? -1 : 1), 0);
            return result;
        }

        if (abs(dividend) < abs(divisor))
            return make_pair(0, dividend);
        int halfIntMax = INT_MAX >> 1;
        int timesDivisor = divisor;
        int times = 1;
        while (abs(timesDivisor) <= halfIntMax && abs(timesDivisor) <= (abs(dividend) >> 1))
            timesDivisor <<= 1, times <<= 1;
        int remainDividend = dividend;
        int result = 0;
        if (abs(dividend) >= abs(timesDivisor))
            result += isDiffSign ? -times : times, remainDividend -= isDiffSign ? -timesDivisor : timesDivisor;
        auto subResult = divideWithRemain(remainDividend, divisor);
        return make_pair(subResult.first + result, subResult.second);
    }

public:
    int divide(int dividend, int divisor)
    {
        return divideWithRemain(dividend, divisor).first;
    }
};