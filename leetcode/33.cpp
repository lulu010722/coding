#include "header.h"

class Solution
{
private:
    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        int l = left;
        int r = right;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        if (nums[l] == target)
            return l;
        return -1;
    }

public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        int leftValue = nums[left];
        int rightValue = nums[right];

        while (left < right && nums[left] > nums[right])
        {
            int middle = (left + right) / 2;
            if (nums[middle] >= leftValue)
                left = middle + 1;
            else if (nums[middle] < rightValue)
                right = middle;
        }
        return max(binarySearch(nums, target, 0, left - 1), binarySearch(nums, target, left, n - 1));
    }
};