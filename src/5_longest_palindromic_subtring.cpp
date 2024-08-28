#include <string>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            auto lhs = it - 1;
            auto rhs = it + 1;
            if (*it == *rhs)
            {
            }
        }
    }
};

// void MedianOfTwoSortedArraysCommon(vector<int> nums1, vector<int> nums2, double expected)
// {
//     Solution solution;
//     EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), expected);
// }

// TEST(MedianOfTwoSortedArrays, Case1)
// {
//     MedianOfTwoSortedArraysCommon({1, 3}, {2}, 2);
// }

// TEST(MedianOfTwoSortedArrays, Case2)
// {
//     MedianOfTwoSortedArraysCommon({1, 2}, {3, 4}, 2.5);
// }