#include <vector>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<int> twoSum2(std::vector<int> &numbers, int target)
    {
        int lhs = 0;
        int rhs = numbers.size() - 1;
        while (true)
        {
            int sum = numbers[rhs] + numbers[lhs];
            if (sum > target)
            {
                --rhs;
            }
            else if (sum < target)
            {
                ++lhs;
            }
            else
            {
                return {lhs + 1, rhs + 1};
            }
        }
    }
};

void TwoSum2Common(std::vector<int> nums, int target)
{
    Solution solution;
    auto result = solution.twoSum2(nums, target);
}

TEST(TwoSum2, Case1)
{
    TwoSum2Common({2, 7, 11, 15}, 9);
}

TEST(TwoSum2, Case2)
{
    TwoSum2Common({2, 3, 4}, 6);
}

TEST(TwoSum2, Case3)
{
    TwoSum2Common({-1, 0}, -1);
}
