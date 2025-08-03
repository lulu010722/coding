#include "header.h"

class Solution
{

public:
    // 动态规划
    // int trap(vector<int> &height)
    // {
    //     int n = height.size();
    //     if (n <= 2)
    //         return 0;
    //     vector<int> leftMax(n);
    //     vector<int> rightMax(n);
    //     leftMax[0] = height[0];
    //     rightMax[n - 1] = height[n - 1];
    //     for (int i = 1; i < n; i++)
    //         leftMax[i] = max(height[i], leftMax[i - 1]);
    //     for (int i = n - 2; i >= 0; i--)
    //         rightMax[i] = max(height[i], rightMax[i + 1]);

    //     int answer = 0;
    //     for (int i = 0; i < n; i++)
    //         answer += min(leftMax[i], rightMax[i]) - height[i];

    //     return answer;
    // }

    // 单调栈
    // int trap(vector<int> &height)
    // {
    //     int n = height.size();
    //     if (n <= 2)
    //         return 0;
    //     int answer = 0;
    //     stack<int> s;
    //     s.push(0);
    //     for (int i = 1; i < n; i++)
    //     {
    //         if (height[s.top()] <= height[i])
    //         {
    //             while (true)
    //             {
    //                 int top = s.top();
    //                 s.pop();
    //                 if (s.empty())
    //                     break;
    //                 answer += (i - s.top() - 1) * (min(height[i], height[s.top()]) - height[top]);
    //                 if (height[s.top()] > height[i])
    //                     break;
    //             }
    //         }
    //         s.push(i);
    //     }
    //     return answer;
    // }

    // 双指针
    int trap(vector<int> &height)
    {
        int n = height.size();
        int answer = 0;
        int left = 0, right = n - 1, leftMax = 0, rightMax = 0;
        while (left <= right)
        {
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if (height[left] <= height[right])
                answer += leftMax - height[left++];
            else 
                answer += rightMax - height[right--];
        }
        return answer;
    }
};