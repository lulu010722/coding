#include "header.h"

class Solution
{
private:
    bool isDigits(string s)
    {
        if (s.empty())
            return false;
        for (auto &&c : s)
            if (!isdigit(c))
                return false;
        return true;
    }

    bool isIntegerWithoutExp(string s)
    {
        if (s.empty())
            return false;
        if (s[0] == '-' || s[0] == '+')
            s = s.substr(1);
        if (s.empty())
            return false;
        return isDigits(s);
    }

    bool isExp(string s)
    {
        if (s.empty() || (s[0] != 'e' && s[0] != 'E'))
            return false;
        return isIntegerWithoutExp(s.substr(1));
    }

    bool isInteger(string s)
    {
        auto index = s.find('e');
        if (index != s.npos)
            return isIntegerWithoutExp(s.substr(0, index)) && isExp(s.substr(index));
        index = s.find('E');
        if (index != s.npos)
            return isIntegerWithoutExp(s.substr(0, index)) && isExp(s.substr(index));
        return isIntegerWithoutExp(s);
    }

    bool isDecimalWithoutExp(string s)
    {
        if (s.empty())
            return false;
        if (s[0] == '-' || s[0] == '+')
            s = s.substr(1);
        auto index = s.find('.');
        if (index == s.npos)
            return false;
        if (index == 0)
            return isDigits(s.substr(1));
        if (index == s.size() - 1)
            return isIntegerWithoutExp(s.substr(0, s.size() - 1));
        return isIntegerWithoutExp(s.substr(0, index)) && isDigits(s.substr(index + 1));
    }

    bool isDecimal(string s)
    {
        auto index = s.find('e');
        if (index != s.npos)
            return isDecimalWithoutExp(s.substr(0, index)) && isExp(s.substr(index));
        index = s.find('E');
        if (index != s.npos)
            return isDecimalWithoutExp(s.substr(0, index)) && isExp(s.substr(index));
        return isDecimalWithoutExp(s);
    }

public:
    bool isNumber(string s)
    {
        return isInteger(s) || isDecimal(s);
    }
};