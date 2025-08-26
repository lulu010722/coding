#include "header.h"

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int answer = 0;
        int tempCount = 0;
        for (auto &&c : s)
        {
            if (c == ' ')
            {
                tempCount = 0;
                continue;
            }
            tempCount++;
            answer = tempCount;
        }
        return answer;
    }
};