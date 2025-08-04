#include "header.h"

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        if (nums.size() == 1)
            return {{nums[0]}};
        int last = nums.back();
        nums.pop_back();
        vector<vector<int>> result;
        auto subResult = permuteUnique(nums);
        for (auto &&p : subResult)
        {
            for (int i = 0; i <= p.size(); i++)
            {
                auto temp = p;
                temp.insert(temp.begin() + i, last);
                result.push_back(temp);
            }
        }

        sort(result.begin(), result.end());
        auto newEnd = unique(result.begin(), result.end());
        result.erase(newEnd, result.end());
        return result;
    }
};