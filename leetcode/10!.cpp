#include "header.h"

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        auto isMatch = [&](int i, int j)
        {
            if (i == 0)
                return false;
            if (p[j - 1] == '.')
                return true;
            return s[i - 1] == p[j - 1];
        };

        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] != '*')
                    dp[i][j] = isMatch(i, j) ? dp[i - 1][j - 1] : false;
                else
                    dp[i][j] = isMatch(i, j - 1) ? dp[i - 1][j] || dp[i][j - 2] : dp[i][j - 2];
            }
        }
        return dp[m][n];
    }
};