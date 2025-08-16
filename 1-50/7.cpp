#include "header.h"

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;
        vector<int> digits;
        while (x != 0)
        {
            digits.push_back(x % 10);
            x /= 10;
        }
        int result = 0;
        for (auto iter = digits.begin(); iter != digits.end() - 1; iter++)
        {
            result = result * 10 + *iter;
        }
        int lastDigit = digits[digits.size() - 1];

        // INT_MAX = 0x7fffffff = 2147483647
        int tenthOfIntMax = INT_MAX / 10;
        if (result > 0)
        {
            if (result > tenthOfIntMax)
                return 0;
            else if (result < tenthOfIntMax)
                return result * 10 + lastDigit;
            else if (lastDigit > 7)
                return 0;
            else
                return result * 10 + lastDigit;
        }
        else
        {
            if (result < -tenthOfIntMax)
                return 0;
            else if (result > -tenthOfIntMax)
                return result * 10 + lastDigit;
            else if (lastDigit < -8)
                return 0;
            else
                return result * 10 + lastDigit;
        }

        return 0;
    }
};