#include "header.h"


class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            swap(nums1, nums2);
        }
        int m = nums1.size();
        int n = nums2.size();

        int totalLeft = (m + n + 1) / 2;
        int left = 0;
        int right = m;
        while (left < right)
        {
            int i = (left + right + 1) / 2;
            int j = totalLeft - i;
            if (nums1[i - 1] > nums2[j])
                right = i - 1;
            else
                left = i;
        }
        
        int i = left;
        int j = totalLeft - i;
        int nums1MaxLeft = i == 0 ? INT_MIN : nums1[i - 1];
        int nums1MinRight = i == m ? INT_MAX : nums1[i];
        int nums2MaxLeft = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2MinRight = j == n ? INT_MAX : nums2[j];

        if ((m + n) % 2 == 1)
            return max(nums1MaxLeft, nums2MaxLeft);
        else
            return (max(nums1MaxLeft, nums2MaxLeft) + min(nums1MinRight, nums2MinRight)) / 2.0;
    }
};