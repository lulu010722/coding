#include "header.h"

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int boundary = nums.size() - 1;
        vector<int> after;
        while (boundary > 0 && nums[boundary - 1] >= nums[boundary])
            after.push_back(nums[boundary]), boundary--;
        after.push_back(nums[boundary]);

        if (boundary == 0)
            reverse(nums.begin(), nums.end());
        else
        {
            int &before = nums[boundary - 1];
            for (auto &i : after)
            {
                if (i > before)
                {
                    int temp = before;
                    before = i;
                    i = temp;
                    break;
                }
            }

            for (int i = 0; i < after.size(); i++)
                nums[boundary + i] = after[i];
        }
    }
};