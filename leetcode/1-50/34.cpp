#include "header.h"

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] >= target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        int leftStart = right + 1;
        left = 0, right = n - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] <= target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        int rightEnd = left - 1;
        vector<int> result1 = {leftStart, rightEnd};
        vector<int> result2 = {-1, -1};
        return leftStart <= rightEnd ? result1 : result2;
    }
};