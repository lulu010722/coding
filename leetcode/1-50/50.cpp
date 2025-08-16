#include "header.h"

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == INT_MIN)
            return myPow(x, n + 1) / x;

        bool isNegative = false;
        if (n < 0)
            isNegative = true, n = -n;
        string bits = bitset<32>(n).to_string();
        int topDigit = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i] == '1')
            {
                topDigit = 31 - i;
                break;
            }
        }
        double result = 1.0;
        double curr = x;
        for (int i = 0; i <= topDigit; i++)
        {
            if (bits[31 - i] == '1')
                result *= curr;
            curr *= curr;
        }

        return isNegative ? 1 / result : result;
    }
};