#include <vector>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>

class Solution
{
public:
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        int sum = 0;
        for (std::size_t i = 0; i < std::size_t(k); ++i)
        {
            sum += nums[i];
        }

        auto max = sum;

        for (std::size_t i = k; i < nums.size(); ++i)
        {
            sum += -nums[i - k] + nums[i];
            if (sum > max)
            {
                max = sum;
            }
        }

        return double(max) / double(k);
    }
};

void MaximumAverageSubarrayCommon(std::vector<int> nums, int k, double expected)
{
    Solution solution;
    ASSERT_EQ(solution.findMaxAverage(nums, k), expected);
}

TEST(MaximumAverageSubarray, Case1)
{
    MaximumAverageSubarrayCommon({1, 12, -5, -6, 50, 3}, 4, 12.75);
}

TEST(MaximumAverageSubarray, Case2)
{
    MaximumAverageSubarrayCommon({5}, 1, 5.0);
}
