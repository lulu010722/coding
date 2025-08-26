#include "header.h"

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        k--;
        vector<int> digits(n, 1);
        vector<int> factorial(n + 1, 1);
        for (int i = 0; i < n; i++)
            digits[i] = i + 1, factorial[i + 1] = factorial[i] * (i + 1);
        string answer;
        for (int i = n - 1; i >= 0; i--)
        {
            int index = k / factorial[i];
            k %= factorial[i];
            answer += digits[index] + '0';
            digits.erase(digits.begin() + index);
        }

        return answer;
    }
};