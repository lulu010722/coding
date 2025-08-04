#include "header.h"

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int curr = 0;
        int step = 0;
        while (curr < n - 1)
        {
            step++;
            if (curr + nums[curr] >= n - 1)
                return step;

            int farthest = 0;
            int farthestIndex = 0;
            for (int i = 1; i <= nums[curr]; i++)
            {
                if (curr + i >= n - 1)
                    return step;
                int far = curr + i + nums[curr + i];
                if (far > farthest)
                    farthest = far, farthestIndex = i;
            }
            if (farthest >= n - 1)
                return step + 1;
            curr += farthestIndex;
        }
        return step;
    }
};