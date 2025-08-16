#include "header.h"

class Solution
{
public:
    // 空间O(n)，时间O(n)
    // int firstMissingPositive(vector<int> &nums)
    // {
    //     unordered_map<int, bool> map;

    //     int n = nums.size();
    //     for (auto i : nums)
    //         if (i > 0)
    //             map[i] = true;
    //     for (int i = 1; i <= n + 1; i++)
    //     {
    //         if (map[i])
    //             continue;
    //         return i;
    //     }
    //     return 0;
    // }

    // 空间其实也是O(n)只不过是原地用的输入的空间，时间O(n)
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (auto &&num : nums)
            if (num <= 0)
                num = n + 1;

        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);
            if (num <= n)
                nums[num - 1] = -abs(nums[num - 1]);
        }

        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                return i + 1;

        return n + 1;
    }
};