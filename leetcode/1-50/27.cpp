#include "header.h"

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        vector<int> result;
        for (auto i : nums)
            if (i != val)
                result.push_back(i);

        for (int i = 0; i < result.size(); i++)
            nums[i] = result[i];
        return result.size();
    }
};