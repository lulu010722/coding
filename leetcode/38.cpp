#include "header.h"

class Solution
{
public:
    string countAndSay(int n)
    {
        string RLE = "1";
        for (int i = 1; i < n; i++)
        {
            string curr;
            int j = 0;
            while (j < RLE.size())
            {
                int cnt = 0;
                char c = RLE[j];
                while (RLE[j] == c)
                    j++, cnt++;
                curr += to_string(cnt) + c;
            }
            RLE = curr;
        }
        return RLE;
    }
};