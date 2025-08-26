#include "header.h"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int farthest = 0;
        for (int i = 0; i <= farthest; i++)
        {
            if (farthest >= nums.size() - 1)
                return true;
            farthest = max(farthest, i + nums[i]);
        }
        return false;
    }
};