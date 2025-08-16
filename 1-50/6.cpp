#include "header.h"

class Solution
{
public:
    // O(n^2)
    // string convert(string s, int numRows)
    // {
    //     if (numRows == 1)
    //         return s;
    //     int n = s.size();
    //     int cols = n / 2 + 1;
    //     vector<vector<char>> map(numRows, vector<char>(cols, 0));
    //     int it = 0;
    //     int currx = 0;
    //     int curry = 0;
    //     while (s[it])
    //     {
    //         for (int i = 0; i < numRows && s[it]; i++)
    //         {
    //             map[currx++][curry] = s[it++];
    //         }
    //         currx -= 2, curry++;
    //         for (int i = 0; i < numRows - 2 && s[it]; i++)
    //         {
    //             map[currx--][curry++] = s[it++];
    //         }
    //     }
    //     string result;
    //     for (int i = 0; i < numRows; i++)
    //     {
    //         for (int j = 0; j < cols; j++)
    //         {
    //             if (map[i][j])
    //                 result += map[i][j];
    //         }
    //     }
    //     return result;
    // }

    // O(n)
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string result;
        int n = s.size();
        int loopCount = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++)
        {
            for (int j = i; j < n; j += loopCount)
            {
                result += s[j];
                if (i >= 1 && i < numRows - 1)
                {
                    int index = (j / loopCount) * loopCount + loopCount - (j % loopCount);
                    if (index < n)
                        result += s[index];
                }
            }
        }
        return result;
    }
};