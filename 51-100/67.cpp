#include "header.h"

class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string answer;
        bool carry = false;
        int longer = max(a.size(), b.size());
        for (int i = 0; i < longer; i++)
        {
            int add1 = 0, add2 = 0;
            if (i < a.size())
                add1 = a[i] - '0';
            if (i < b.size())
                add2 = b[i] - '0';
            int temp = add1 + add2 + carry;
            carry = temp >= 2;
            answer += (temp & 1) + '0';
        }
        if (carry)
            answer += '1';
        reverse(answer.begin(), answer.end());
        return answer;
    }
};