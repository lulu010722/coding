#include "header.h"

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() == 1)
            return {{nums[0]}};
        int last = nums.back();
        nums.pop_back();
        vector<vector<int>> result;
        auto subResult = permute(nums);
        for (auto &&p : subResult)
        {
            for (int i = 0; i <= p.size(); i++)
            {
                auto temp = p;
                temp.insert(temp.begin() + i, last);
                result.push_back(temp);
            }
        }
        return result;
    }
};