#include "header.h"

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        int result = target;

        for (int i = 0; i < n; i++)
        {
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int diff = nums[i] + nums[left] + nums[right] - target;
                if (abs(diff) < minDiff)
                {
                    minDiff = abs(diff);
                    result = nums[i] + nums[left] + nums[right];
                }
                if (diff < 0)
                    left++;
                else if (diff > 0)
                    right--;
                else
                    return 0;
            }
        }
        return result;
    }
};