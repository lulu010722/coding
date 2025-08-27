#include "header.h"

class Solution
{
private:
public:
    int uniquePaths(int m, int n)
    {
        int lower = m + n - 2, upper = min(m - 1, n - 1);
        vector<vector<int>> combinationNums(lower + 1, vector<int>(upper + 1, 1));
        for (int l = 0; l <= lower; l++)
            for (int u = 1; u <= min(upper, l - 1); u++)
                combinationNums[l][u] = combinationNums[l - 1][u] + combinationNums[l - 1][u - 1];
        return combinationNums[lower][upper];
    }
};