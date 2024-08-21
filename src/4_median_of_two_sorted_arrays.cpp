#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> combined;
        combined.reserve(nums1.size() + nums2.size());
        combined.insert(combined.cend(), nums1.cbegin(), nums1.cend());
        combined.insert(combined.cend(), nums2.cbegin(), nums2.cend());
        std::sort(combined.begin(), combined.end());

        if (combined.size() % 2 == 1)
        {
            return combined[(combined.size() - 1) / 2];
        }
        else
        {
            auto half_of_size = combined.size() / 2;
            return (combined[half_of_size - 1] + combined[half_of_size]) / 2.0;
        }
    }
};

void MedianOfTwoSortedArraysCommon(vector<int> nums1, vector<int> nums2, double expected)
{
    Solution solution;
    EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), expected);
}

TEST(MedianOfTwoSortedArrays, Case1)
{
    MedianOfTwoSortedArraysCommon({1, 3}, {2}, 2);
}

TEST(MedianOfTwoSortedArrays, Case2)
{
    MedianOfTwoSortedArraysCommon({1, 2}, {3, 4}, 2.5);
}