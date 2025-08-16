#include "header.h"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;

        int area = (right - left) * min(height[left], height[right]);

        while (left < right)
        {
            if (height[left] < height[right])
            {
                int tempLeftHighest = height[left];
                while (left < right && height[left] <= tempLeftHighest)
                    left++;
            }
            else
            {
                int tempRightHighest = height[right];
                while (left < right && height[right] <= tempRightHighest)
                    right--;
            }
            area = max(area, (right - left) * min(height[left], height[right]));
        }
        return area;
    }
};