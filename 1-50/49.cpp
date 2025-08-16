#include "header.h"

class Solution
{
public:
    // 时间击败5.2%
    // vector<vector<string>> groupAnagrams(vector<string> &strs)
    // {
    //     vector<size_t> hashes;
    //     hash<string> strHash;
    //     vector<vector<string>> result;
    //     for (auto &&s : strs)
    //     {
    //         auto temp = s;
    //         sort(temp.begin(), temp.end());
    //         auto h = strHash(temp);
    //         auto it = lower_bound(hashes.begin(), hashes.end(), h);
    //         if (it != hashes.end() && *it == h)
    //             result[it - hashes.begin()].push_back(s);
    //         else
    //         {
    //             int index = it - hashes.begin();
    //             hashes.insert(it, h);
    //             result.insert(result.begin() + index, {s});
    //         }
    //     }
    //     return result;
    // }

    // 时间击败94.81%
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (auto &&s : strs)
        {
            auto temp = s;
            sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &&vec : map)
            result.push_back(vec.second);

        return result;
    }
};