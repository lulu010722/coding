#include "header.h"

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> fibonacci(n + 1, 1);
        for (int i = 2; i < n + 1; i++)
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        return fibonacci[n];
    }
};