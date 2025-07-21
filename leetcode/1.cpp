
#include "header.h"

class Solution
{
public:

    // O(nlogn)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> solution;
        vector<pair<int, int>> numsWithIndex;

        for (int i = 0; i < n; i++)
        {
            numsWithIndex.push_back(make_pair(nums[i], i));
        }

        sort(numsWithIndex.begin(), numsWithIndex.end());
        int first = 0;
        int second = n - 1;
        while (first < second)
        {
            int firstValue = numsWithIndex[first].first;
            int secondValue = numsWithIndex[second].first;
            if (firstValue + secondValue < target)
            {
                first++;
            }
            else if (firstValue + secondValue > target)
            {
                second--;
            }
            else
            {
                solution.push_back(numsWithIndex[first].second);
                solution.push_back(numsWithIndex[second].second);
                break;
            }
        }

        return solution;
    }

    // O(n^2)
    // vector<int> twoSum(vector<int> &nums, int target)
    // {
    //     int n = nums.size();
    //     vector<int> solution;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             if (nums[i] + nums[j] == target)
    //             {
    //                 solution.push_back(i);
    //                 solution.push_back(j);
    //             }
    //         }
    //     }
    //     return solution;
    // }
};