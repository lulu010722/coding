#include "header.h"

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        vector<int> digits;
        while (x > 0)
        {
            digits.push_back(x % 10);
            x /= 10;
        }
        vector<int> oldDigits(digits);
        reverse(digits.begin(), digits.end());
        return oldDigits == digits;
    }
};