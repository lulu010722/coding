#include "4.cpp"
using namespace std;
int main()
{
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}