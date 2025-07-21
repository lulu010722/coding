#include "header.h"

class Solution
{
public:
    // 用unordered_map<pair<int, int>, bool>不如直接二维vector快（前面的过不了。。）
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        pair<int, int> maxStringInterval = make_pair(0, 1);
        for (int i = 0; i < n; i++)
            dp[i][0] = dp[i][1] = 1;
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                bool isPalindrome = (s[i] == s[i + len - 1]) && dp[i + 1][len - 2];
                dp[i][len] = isPalindrome;
                maxStringInterval = isPalindrome ? make_pair(i, len) : maxStringInterval;
            }
        }
        return s.substr(maxStringInterval.first, maxStringInterval.second);
    }
};