#include "header.h"

class Solution
{
    // O(m)
    void getPattern(vector<int> &next, const string &needle)
    {
        for (auto &i : next)
            i = 0;
        next[0] = -1;
        for (int i = 2, j = 0; i < next.size(); i++, j++)
        {
            while (j >= 0)
            {
                if (needle[i - 1] == needle[j])
                {
                    next[i] = j + 1;
                    break;
                }
                else
                    j = next[j];
            }
        }
    }


    // O(m^3)
    // void getPattern(vector<int> &pattern, const string &needle)
    // {
    //     for (auto &i : pattern)
    //         i = 0;
    //     pattern[0] = -1;

    //     for (int i = 2; i < needle.size(); i++)
    //     {
    //         for (int j = 1; j < i; j++)
    //         {
    //             bool match = true;
    //             for (int k = 0; k < j; k++)
    //             {
    //                 if (needle[k] != needle[i - j + k])
    //                 {
    //                     match = false;
    //                     break;
    //                 }
    //             }
    //             pattern[i] = match ? j : pattern[i];
    //         }
    //     }
    // }

public:
    int strStr(string haystack, string needle)
    {
        vector<int> pattern(needle.size());
        getPattern(pattern, needle);

        int i = 0;
        while (i < haystack.size())
        {
            int j = 0;
            while (j >= 0)
            {
                if (haystack[i] == needle[j])
                {
                    if (j == needle.size() - 1)
                        return i - j;
                    else
                        i++, j++;
                }
                else
                    j = pattern[j];
            }
            i++;
        }

        return -1;
    }
};