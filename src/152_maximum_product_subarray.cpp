#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int max = nums[0];
        int sub = 1;
        for (auto num : nums)
        {
            sub *= num;
            max = std::max(max, sub);
            if (sub == 0)
            {
                sub = 1;
            }
        }
        sub = 1;
        for (auto it = nums.rbegin(); it != nums.rend(); ++it)
        {
            sub *= *it;
            max = std::max(max, sub);
            if (sub == 0)
            {
                sub = 1;
            }
        }

        return max;
    }
};

void MaximumProductSubarrayCommon(std::vector<int> nums, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.maxProduct(nums), expected);
}

TEST(MaximumProductSubarray, Case0)
{
    MaximumProductSubarrayCommon({2, 3, -2, 4}, 6);
}

TEST(MaximumProductSubarray, Case1)
{
    MaximumProductSubarrayCommon({-2, 0, -1}, 0);
}

TEST(MaximumProductSubarray, Case2)
{
    MaximumProductSubarrayCommon({2, -5, -2, -4, 3}, 24);
}
