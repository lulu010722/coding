#include "header.h"

class Solution
{
public:
    int myAtoi(string s)
    {
        s.push_back(0);
        int result = 0;
        int it = 0;
        // 第一步：删除前导空格
        while (s[it] == ' ')
            it++;

        // 第二步：确定符号
        bool isNegative = false;
        if (s[it] == '-')
            it++, isNegative = true;
        else if (s[it] == '+')
            it++, isNegative = false;

        // 第三步：删除前导零
        while (s[it] == '0')
            it++;

        // 第四步：读取实际数字并舍入
        int tenOfIntMax = INT_MAX / 10;
        while (isdigit(s[it]))
        {
            int digit = s[it] - '0';
            if (result < tenOfIntMax)
                result = result * 10 + digit;
            else if (result > tenOfIntMax)
            {
                if (isNegative)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            else
            {
                if (isNegative)
                {
                    if (digit > 8 || isdigit(s[it + 1]))
                        return INT_MIN;
                    else
                        return -result * 10 - digit;
                }
                else
                {
                    if (digit > 7 || isdigit(s[it + 1]))
                        return INT_MAX;
                    else
                        return result * 10 + digit;
                }
            }
            it++;
        }
        return isNegative ? -result : result;
    }
};