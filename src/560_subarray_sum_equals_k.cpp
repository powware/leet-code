#include <unordered_map>
#include <iostream>
#include <optional>

#include <gtest/gtest.h>

class Solution
{
public:
    int subarraySum(std::vector<int> &nums, int k)
    {
        int result = 0;
        int sum = 0;
        appearances_[0] = 1;
        for (std::size_t i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            result += appearances_[sum - k];

            appearances_[sum]++;
        }

        return result;
    }

private:
    std::unordered_map<int, int> appearances_;
};

void SubarraySumEqualsKCommon(std::vector<int> nums, int k, int expected)
{
    Solution solution;
    ASSERT_EQ(solution.subarraySum(nums, k), expected);
}

// TEST(SubarraySumEqualsK, Case1)
// {
//     SubarraySumEqualsKCommon({1, 1, 1}, 2, 2);
// }

// TEST(SubarraySumEqualsK, Case2)
// {
//     SubarraySumEqualsKCommon({1, 2, 3}, 3, 2);
// }

TEST(SubarraySumEqualsK, Case3)
{
    SubarraySumEqualsKCommon({1, 2, 3, 4, -3, 1, 2, 4, -2}, 3, 3);
}

// TEST(SubarraySumEqualsK, Case4)
// {
//     SubarraySumEqualsKCommon({-1, 0, 1, 1, 1, -1, 1, -1}, 0, 1);
// }
