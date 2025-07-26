#include "header.h"

class Solution
{
    unordered_map<int, char> map;

    void makeMap()
    {
        map.insert(make_pair(1, 'I'));
        map.insert(make_pair(5, 'V'));
        map.insert(make_pair(10, 'X'));
        map.insert(make_pair(50, 'L'));
        map.insert(make_pair(100, 'C'));
        map.insert(make_pair(500, 'D'));
        map.insert(make_pair(1000, 'M'));
    }

public:
    string intToRoman(int num)
    {
        makeMap();
        string result;
        while (num)
        {
            string numStr = to_string(num);
            int numBits = numStr.size();
            int firstDigit = numStr[0] - '0';
            int powerOfTen = 1;
            for (int i = 1; i < numBits; i++)
                powerOfTen *= 10;

            if (firstDigit < 4)
                for (int i = 0; i < firstDigit; i++)
                    result += map[powerOfTen], num -= powerOfTen;

            else if (firstDigit == 4)
                result += map[powerOfTen], result += map[5 * powerOfTen], num -= 4 * powerOfTen;
            else if (firstDigit < 9)
            {
                result += map[5 * powerOfTen], num -= 5 * powerOfTen;
                for (int i = 5; i < firstDigit; i++)
                    result += map[powerOfTen], num -= powerOfTen;
            }
            else
                result += map[powerOfTen], result += map[10 * powerOfTen], num -= 9 * powerOfTen;
        }
        return result;
    }
};