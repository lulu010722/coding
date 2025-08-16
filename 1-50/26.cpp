#include "header.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == result.back())
                continue;
            result.push_back(nums[i]);
        }
        for (int i = 0; i < result.size(); i++)
            nums[i] = result[i];

        return result.size();
    }
};