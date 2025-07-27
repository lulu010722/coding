#include "header.h"

class Solution
{
    vector<vector<string>> map;

public:
    Solution()
    {
        map.push_back({});
        map.push_back({});
        map.push_back({"a", "b", "c"});
        map.push_back({"d", "e", "f"});
        map.push_back({"g", "h", "i"});
        map.push_back({"j", "k", "l"});
        map.push_back({"m", "n", "o"});
        map.push_back({"p", "q", "r", "s"});
        map.push_back({"t", "u", "v"});
        map.push_back({"w", "x", "y", "z"});
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        if (digits.size() == 1)
            return map[digits[0] - '0'];
        auto post = letterCombinations(digits.substr(1));

        vector<string> result;
        for (auto c : map[digits[0] - '0'])
            for (auto sub : post)
                result.push_back(c + sub);
        return result;
    }
};