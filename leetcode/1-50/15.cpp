#include "header.h"

struct Triple
{
    int i, j, k;

    bool operator==(const Triple &other) const
    {
        return i == other.i && j == other.j && k == other.k;
    }
};

namespace std
{
    template <>
    struct hash<Triple>
    {
        size_t operator()(const Triple &triple) const
        {
            size_t first = hash<int>()(triple.i);
            size_t second = hash<int>()(triple.j);
            size_t third = hash<int>()(triple.k);
            return first ^ (second << 1) ^ (third << 2);
        }
    };
}

class Solution
{

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;
        unordered_map<Triple, bool> repeatCheck;
        int n = nums.size();
        vector<vector<int>> result;

        for (int i = 0; i < n; i++)
            map[nums[i]] = i;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int k = map[-nums[i] - nums[j]];
                if (k > j && !repeatCheck[{nums[i], nums[j], nums[k]}])
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    repeatCheck[{nums[i], nums[j], nums[k]}] = true;
                }
            }
        }
        return result;
    }
};