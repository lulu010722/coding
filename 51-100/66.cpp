#include "header.h"

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0 && carry; i--)
        {
            digits[i]++;
            carry = digits[i] >= 10;
            digits[i] = (digits[i] == 10 ? 0 : digits[i]);
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};