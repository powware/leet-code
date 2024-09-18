#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        const auto n = nums.size();
        int max = nums[0];
        int previous = nums[0];
        for (std::size_t i = 1; i < n; ++i)
        {
            int current = std::max(nums[i], nums[i] + previous);
            if (current > max)
            {
                max = current;
            }
            previous = current;
        }

        return max;
    }
};

void MaximumSubarrayCommon(std::vector<int> cost, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.maxSubArray(cost), expected);
}

TEST(MaximumSubarray, Case1)
{
    MaximumSubarrayCommon({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
}

TEST(MaximumSubarray, Case2)
{
    MaximumSubarrayCommon({1}, 1);
}

TEST(MaximumSubarray, Case3)
{
    MaximumSubarrayCommon({5, 4, -1, 7, 8}, 23);
}
