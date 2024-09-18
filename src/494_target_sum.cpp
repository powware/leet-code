#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

class Solution
{
public:
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        int result = 0;

        ways(nums, 0, nums.size(), 0, target, result);

        return result;
    }

private:
    void ways(std::vector<int> &nums, int i, int end, int sum, int target, int &result)
    {
        int num = nums[i];

        if (++i >= end)
        {
            if (sum + num == target)
            {
                ++result;
            }
            if (sum - num == target)
            {
                ++result;
            }
            return;
        }

        ways(nums, i, end, sum + num, target, result);
        ways(nums, i, end, sum - num, target, result);
    }
};

void TargetSumCommon(std::vector<int> nums, int target, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.findTargetSumWays(nums, target), expected);
}

TEST(TargetSum, Case1)
{
    TargetSumCommon({1, 1, 1, 1, 1}, 3, 5);
}

TEST(TargetSum, Case2)
{
    TargetSumCommon({1}, 1, 1);
}
