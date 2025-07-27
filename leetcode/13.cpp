#include "header.h"

class Solution
{
private:
    unordered_map<char, int> map;
    void makeMap()
    {
        map.insert(make_pair('I', 1));
        map.insert(make_pair('V', 5));
        map.insert(make_pair('X', 10));
        map.insert(make_pair('L', 50));
        map.insert(make_pair('C', 100));
        map.insert(make_pair('D', 500));
        map.insert(make_pair('M', 1000));
    }

public:
    int romanToInt(string s)
    {
        makeMap();
        int result = 0;
        auto it = s.begin();
        while (it != s.end())
        {
            if (it + 1 != s.end() && map[*(it + 1)] > map[*it])
                result += map[*(it + 1)] - map[*it], it += 2;
            else
                result += map[*(it)], it++;
        }
        return result;
    }
};