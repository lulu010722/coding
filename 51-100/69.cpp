#include "header.h"

class Solution
{
public:
    int mySqrt(int x)
    {
        int right = 46341; // 2 ^ 32 - 1的平方根取整
        int left = 0;
        while (left < right)
        {
            int mid = (left + right) / 2;
            int midSquare = mid * mid;
            if (midSquare == x)
                return mid;
            if (midSquare < x)
                left = mid + 1;
            else
                right = mid;
        }
        return left - 1;
    }
};