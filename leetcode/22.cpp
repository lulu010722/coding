#include "header.h"

class Solution
{
private:
    vector<vector<int>> getCombinations(int n, int m)
    {
        assert(n >= m);
        if (m == 0)
            return {{}};
        vector<vector<int>> result;
        for (int i = m - 1; i < n; i++)
        {
            auto combinations = getCombinations(i, m - 1);
            for (auto c : combinations)
            {
                c.push_back(i);
                result.push_back(c);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }

public:
    // 用组合数解决
    // vector<string> generateParenthesis(int n)
    // {
    //     auto combinations = getCombinations(2 * n, n);
    //     vector<string> result;
    //     for (auto c : combinations)
    //     {
    //         bool valid = true;
    //         for (int i = 0; i < c.size(); i++)
    //         {
    //             if (c[i] > 2 * i)
    //             {
    //                 valid = false;
    //                 break;
    //             }
    //         }
    //         if (valid)
    //         {
    //             string s(2 * n, ')');
    //             for (auto v : c)
    //                 s[v] = '(';
    //             result.push_back(s);
    //         }
    //     }
    //     return result;
    // }

    vector<string> generateParenthesis(int n)
    {
        if (n == 1)
            return {"()"};

        auto subs = generateParenthesis(n - 1);
        vector<string> result;
        unordered_set<string> check;

        for (auto sub : subs)
        {
            for (int i = 0; i <= sub.size(); i++)
            {
                string temp = sub;
                string s = temp.insert(i, "()");
                if (check.insert(s).second)
                    result.push_back(s);
            }
        }
        return result;
    }
};