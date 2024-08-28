#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> combined(nums1.size() + nums2.size());

        std::size_t i = 0, j = 0, c = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (i == nums1.size())
            {
                combined[c++] = nums2[j++];
            }
            else if (j == nums2.size())
            {
                combined[c++] = nums1[i++];
            }
            else
            {
                if (nums1[i] < nums2[j])
                {
                    combined[c++] = nums1[i++];
                }
                else
                {
                    combined[c++] = nums2[j++];
                }
            }
        }
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