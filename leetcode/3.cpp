#include "header.h"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;
        int start = 0;
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            map[s[i]]++;
            while (start < i && map[s[i]] > 1)
            {   
                map[s[start++]]--;
            }
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};