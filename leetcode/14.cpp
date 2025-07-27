#include "header.h"

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int minSize = INT_MAX;
        int n = strs.size();
        string result;
        for (auto &s : strs)
            minSize = min(minSize, (int)s.size());
        for (int i = 0; i < minSize; i++)
        {
            char c = strs[0][i];
            bool isSame = true;
            for (int j = 1; j < n; j++)
                if (strs[j][i] != c)
                {
                    isSame = false;
                    break;
                }
            if (isSame)
                result += c;
            else
                break;
        }
        return result;
    }
};