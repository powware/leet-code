#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

class Solution
{
public:
    int maxSubarraySumCircular(std::vector<int> &nums)
    {
        int max = nums[0];
        int min = nums[0];
        int sum = 0;
        int current_max = 0;
        int current_min = 0;
        for (auto num : nums)
        {
            sum += num;
            current_max = std::max(num, num + current_max);
            max = std::max(max, current_max);
            current_min = std::min(num, num + current_min);
            min = std::min(min, current_min);
        }

        return max > 0 ? std::max(max, sum - min) : max;
    }
};

void MaximumSumCircularSubarrayCommon(std::vector<int> cost, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.maxSubarraySumCircular(cost), expected);
}

TEST(MaximumSumCircularSubarray, Case0)
{
    MaximumSumCircularSubarrayCommon({9, -4, -7, 9}, 18);
}

TEST(MaximumSumCircularSubarray, Case1)
{
    MaximumSumCircularSubarrayCommon({1, -2, 3, -2}, 3);
}

TEST(MaximumSumCircularSubarray, Case2)
{
    MaximumSumCircularSubarrayCommon({5, -3, 5}, 10);
}

TEST(MaximumSumCircularSubarray, Case3)
{
    MaximumSumCircularSubarrayCommon({-3, -2, -3}, -2);
}
