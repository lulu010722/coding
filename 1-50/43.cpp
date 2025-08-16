#include "header.h"

class Solution
{
private:
    void trim(deque<int> &nums)
    {
        while (!nums.empty())
            if (nums[nums.size() - 1] == 0)
                nums.pop_back();
            else
                break;

        if (nums.empty())
            nums.push_back(0);
    }

    deque<int> addDeque(const deque<int> &nums1, const deque<int> &nums2)
    {
        deque<int> temp1(nums1);
        deque<int> temp2(nums2);

        if (temp1.size() > temp2.size())
            swap(temp1, temp2);

        int m = temp1.size();
        int n = temp2.size();

        deque<int> result(n + 1, 0);
        int carry = 0;
        for (int i = 0; i < m; i++)
        {
            int temp = temp1[i] + temp2[i] + carry;
            result[i] = temp % 10;
            carry = temp / 10;
        }
        for (int i = m; i < n; i++)
        {
            int temp = temp2[i] + carry;
            result[i] = temp % 10;
            carry = temp / 10;
        }
        if (carry)
            result[n] = 1;
        else
            result.pop_back();

        return result;
    }

    deque<int> mulDigit(const deque<int> &nums1, int digit)
    {
        int n = nums1.size();
        deque<int> result(n + 1);
        int carry = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = nums1[i] * digit + carry;
            result[i] = temp % 10;
            carry = temp / 10;
        }
        if (carry)
            result[n] = carry;
        else
            result.pop_back();

        return result;
    }

    deque<int> mulDeque(const deque<int> &nums1, const deque<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        deque<int> result;

        for (int i = 0; i < m; i++)
        {
            auto temp = mulDigit(nums2, nums1[i]);
            for (int j = 0; j < i; j++)
                temp.push_front(0);
            result = addDeque(temp, result);
        }
        return result;
    }

public:
    string multiply(string num1, string num2)
    {
        int m = num1.size();
        int n = num2.size();
        deque<int> nums1(m);
        deque<int> nums2(n);

        for (int i = 0; i < m; i++)
            nums1[i] = num1[m - 1 - i] - '0';
        for (int i = 0; i < n; i++)
            nums2[i] = num2[n - 1 - i] - '0';

        auto result = mulDeque(nums1, nums2);
        trim(result);

        string s;
        for (int i = result.size() - 1; i >= 0; i--)
            s += result[i] + '0';
        return s;
    }
};