#include "header.h"

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // 动规数组不用记录左右两个边界，只记录以i结尾的最长串即可，前者O(n^2)，后者O(n)
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] == '(')
            {
                dp[i] = 0;
                continue;
            }

            int sub = dp[i - 1];
            if (sub == 0 && s[i - 2] == '(')
                dp[i] = dp[i - 2] + 2;
            else if (i == sub + 1)
                dp[i] = 0;
            else if (i >= sub + 2 && s[i- sub - 2] == '(')
                dp[i] = dp[i - 1] + 2 + dp[i - sub - 2];
        }

        return *max_element(dp.begin(), dp.end());
    }
};