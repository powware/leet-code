#include <vector>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>

class Solution
{
public:
    int peakIndexInMountainArray(std::vector<int> &arr)
    {
        std::size_t left = 0, right = arr.size();
        while (true)
        {
            std::size_t middle = (left + right) / 2;
            if (arr[middle] > arr[middle + 1] && arr[middle] > arr[middle - 1])
            {
                return middle;
            }
            else if (arr[middle] > arr[middle + 1])
            {
                right = middle;
            }
            else if (arr[middle] > arr[middle - 1])
            {
                left = middle;
            }
        }
    }
};

void PeakIndexInMountainArrayCommon(std::vector<int> nums)
{
    Solution solution;
    auto result = solution.peakIndexInMountainArray(nums);
}

TEST(PeakIndexInMountainArray, Case1)
{
    PeakIndexInMountainArrayCommon({0, 9, 10, 7, 6, 5, 4, 3, 2, 1});
}
